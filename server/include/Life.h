#ifndef _LIFE_H_
#define _LIFE_H_


/*La vida de los personajes deberia leerse del config.yaml*/

class Life{
    private:
        Life(const Life &other) = delete;
		Life& operator=(const Life &other) = delete;
		Life& operator=(Life &&other) = delete;

    int value;

    public:
        Life();
        ~Life();

        void decreaseLife(int valueToDecrease);
        int getLife();
        // void getInitialValue();  Aca lee del config.yaml        
};

#endif