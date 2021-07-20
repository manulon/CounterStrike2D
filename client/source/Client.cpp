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
        try{
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
    while (isRunning){
        do{
            info = nonBlockingQueue.pop();
            if (info != nullptr) {
                // std::string pepe(message);
                info->update(map);
            }
        } while (info != NULL);
        isRunning = eh.handleEvents();
        map.renderAll();
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
    }
}
