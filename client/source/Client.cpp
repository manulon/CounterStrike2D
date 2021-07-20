#include "Client.h"
#include "EventHandler.h"
#include "Window.h"
#include "Info.h"
#include "TileMap.h"
#include <chrono>
#include <thread>
#include "Stencil.h"
#include "Camera.h"
#include "InitialMenu.h"

void Client::run(const char * host, const char *service){
    InitialMenu menu;
    bool isRunning(true);
    while (isRunning){
        menu.clear();
        isRunning = menu.handleEvents();
        menu.render();
    }
    menu.close();

    if (menu.startGame()){
        Socket skt;
        skt.connect(host,service);

        Window window("Counter Strike 2D", 800, 600, 
                    SDL_WINDOW_RESIZABLE, 
                    SDL_INIT_VIDEO | SDL_INIT_AUDIO);
        TileMap map(window, menu.getMapPath().c_str(), menu.getTilesPath(), "../assets/gfx/tiles/obstacles.png");
        ThreadClientReceiver receiver(skt, nonBlockingQueue);
        ThreadClientSender sender(skt, blockingQueue, 1);
        

        receiver.spawn();
        sender.spawn();

        std::shared_ptr<ClientMessage> msg (new LoginMessage(JOIN,menu.getMapPath().c_str()));
        blockingQueue.push(msg);
        try {
            gameLoop(map);
        } catch (std::exception &e) {
            std::cout<<"PERDISTE\n";
            blockingQueue.close();
            skt.close();
        }
        
        receiver.join();
        sender.join();
    }
}

void Client::gameLoop(TileMap &map){
    bool isRunning = true;
    EventHandler eh(blockingQueue,map);
    std::shared_ptr<Info> info;
    int rest = 0; 
    int behind = 0;
    int lost = 0;
    int rate = 1000/60;
    auto t1 = std::chrono::steady_clock::now();
    auto t2 = t1;
    std::chrono::duration<double, std::milli> diff;

    while (isRunning) {
        //executeFrame();
        do {
            info = nonBlockingQueue.pop();
            if (info != nullptr) {
                info->update(map);
            }
        } while (info != NULL);
        isRunning = eh.handleEvents();
        map.renderAll();

        t2 = std::chrono::steady_clock::now();
        diff = t2 - t1;
        rest = rate - std::ceil(diff.count());

        if (rest < 0) {
            behind = -rest;
            rest = rate - (behind % rate);
            lost = behind + rate;
            t1 += std::chrono::milliseconds(lost);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(rest));
    }
}
