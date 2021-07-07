#ifndef _DAMAGE_H_
#define _DAMAGE_H_

/*Creo la clase por si llegamos a usar lo de damage triangular etc. */

class Damage{
    private:
        Damage(const Damage &other) = delete;
		Damage& operator=(const Damage &other) = delete;
		Damage& operator=(Damage &&other) = delete;

        int damageValue;

    public:
        Damage();
        ~Damage();

        int getDamage();
        void setDamage(int value);
};

#endif