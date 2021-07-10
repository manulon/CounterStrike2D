#ifndef _CLIENT_H_
#define _CLIENT_H_

#include "Thread.h"
#include <atomic>

class ThreadClient : public Thread {
	private:
		Socket peer;
		bool isRunning;

		ThreadClient(const ThreadClient &other) = delete;
		ThreadClient& operator=(const ThreadClient &other) = delete;
		ThreadClient& operator=(ThreadClient &&other) = delete;

		/*
		 * @brief Ejecuta y crea el nuevo thread.
		 */
		void run() override;

	public:
		/*
		 * @brief Constructor con parametros.
		 * @param peer: Peer del cliente, luego de esta operacion
		 * el peer es movido como miembro de ThreadClient.
		 * @param gamesMonitor: Coleccion que almacena la informacion
		 * sobre las partidas que se estan ejecutando.
		 */
		ThreadClient(Socket &&peer);

		/*
		 * @brief Constructor por movimiento.
		 * @param other: Otro objeto ThreadClient.
		 */
		ThreadClient(ThreadClient &&other);

		/*
		 * @brief Destructor.
		 */
		~ThreadClient();

		/*
		 * @brief Detiene la ejecucion del thread.
		 */
		void stop();

		/* 
		 * @brief Informa si el hilo dejo de ejecutarse.
		 * @return bool: Devuelve true si el hilo ya termino
		 * su trabajo o false en caso contrario.
		 */
		bool isDead() const;
};

#endif // _CLIENT_H_