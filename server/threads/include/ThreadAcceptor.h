#ifndef _THREAD_ACCEPTOR_H_
#define _THREAD_ACCEPTOR_H_
#include "Clients.h"
#include "Socket.h"
#include "Thread.h"
#include "ThreadServerReceiver.h"
#include "ThreadServerSender.h"
#include <map>
//#include <atomic>

class ThreadAcceptor : public Thread {
	private:
		Socket acceptor;
		bool isRunning;
		NonBlockingQueue<std::shared_ptr<Event>> &queue;
		std::map<short,std::shared_ptr<BlockingQueue<ServerMessage*>>> & senderQueues;
		// Clients &clients;
		std::map<short,std::tuple<Socket,ThreadServerReceiver*,ThreadServerSender*>> clients;
		ThreadAcceptor(const ThreadAcceptor &other) = delete;
		ThreadAcceptor& operator=(const ThreadAcceptor &other) = delete;
		void cleanDeadClients();

		/*
		 * @brief Ejecuta y crea el nuevo thread.
		 */
		void run() override;

	public:
		/*
		 * Constructor con parametros.
		 * @param service: Puerto en el que se creara
		 * el hilo aceptador.
		 */
		// explicit ThreadAcceptor(const char *service, NonBlockingQueue<std::shared_ptr<Event>> &queue);

		/*
		 * Constructor con parametros.
		 * @param host: Dominio en donde escuchara el socket.
		 * @param service: Puerto en donde enlazara el socket.
		 */
		ThreadAcceptor(const char *host, const char *service,
					   NonBlockingQueue<std::shared_ptr<Event>> &queue, 
					   std::map<short,std::shared_ptr<BlockingQueue<ServerMessage*>>> & senderQueues);

		/*
		 * Constructor por movimiento.
		 * @param other: Otro objeto ThreadAcceptor.
		 */
		ThreadAcceptor(ThreadAcceptor &&other);

		/*
		 * Destructor.
		 */
		~ThreadAcceptor();

		/*
		 * Operador asignacion por movimiento.
		 * @param other: Otro objeto ThreadAcceptor.
		 * @return Devuelve el mismo objeto creado para permitir
		 * asignaciones en cascada.
		 */
		ThreadAcceptor& operator=(ThreadAcceptor &&other);

		/*
		 * Detiene el hilo aceptador.
		 */
		void stop();
};

#endif // _THREAD_ACCEPTOR_H_
