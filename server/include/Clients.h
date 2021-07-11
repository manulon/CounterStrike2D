#ifndef _CLIENTS_H_
#define _CLIENTS_H_

#include "Socket.h"
#include <list>
#include <map>
#include "BlockingQueue.h"
class ThreadClient;

class Clients {
	private:
		std::list<std::unique_ptr<ThreadClient>> clients;
		NonBlockingQueue<std::unique_ptr<ClientEvent>> &queue;
		std::map<int,std::shared_ptr<BlockingQueue<std::string>>> senderQueues;
		Clients(const Clients &other);
		Clients& operator=(const Clients &other);

	public:
		/*
		 * @brief Constructor.
		 */
		Clients( NonBlockingQueue<std::unique_ptr<ClientEvent>> &queue);

		/*
		 * @brief Constructor por movimiento.
		 * @param other: Otro objeto Clients.
		 */
		Clients(Clients &&other);

		/*
		 * @brief Destructor.
		 */
		~Clients();

		/*
		 * @brief Asignacion por movimiento.
		 * @param other: Otro objeto Clients.
		 * @param Clients: Se devuelve a si mismo
		 * para poder ejecutar el operador en cascada.
		 */
		Clients& operator=(Clients &&other);

		/*
		 * @brief Agrega un nuevo cliente a la lista.
		 * @param peer: recibe el peer del cliente a agregar. Esta
		 * operacion mueve el objeto Peer como miembro de la clase.
		 */
		void add(Socket &&peer, int id);

		/*
		 * @brief Libera a los clientes que dejaron de ejecutarse.
		 */
		void cleanDeadClients();

		/*
		 * @brief Detiene ordenadamente a los clientes que controla.
		 */
		void stopClients() const;
};

#endif // _CLIENTS_H_


/*
#ifndef _CLIENT_EVENT_
#define _CLIENT_EVENT_

struct ClientEvent{
    int idClient;
    char opcode;
    int arg;
};

#endif
 */
