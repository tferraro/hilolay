#ifndef hilolay_h__
	#define hilolay_h__

	/* Interface for programs, this is what the programs should use and is implemented in hilolay_internal */

	// TODO: Not working in program without struct, even though it has typedef
	typedef struct hilolay_t {
		int tid;
	} hilolay_t;

	typedef struct hilolay_attr_t {
		int attrs;
	} hilolay_attr_t;

	/**
	 * Initializes the library. Implemented in the client interface.
	 *
	 * Must call hilolay.c#_init function
	 */
	void hilolay_init(void);

	/**
	 * Starts an hilolay thread
	 */
	int hilolay_create(hilolay_t *thread, const hilolay_attr_t *attr, void *(*start_routine)(void *), void *arg);

	/**
	 * Forces a Thread scheduled swap
	 */
	int hilolay_yield(void);

	/**
	 * Joins the given `thread` to the current thread.
	 */
	int hilolay_join(hilolay_t *thread);

	/**
	 * Returns the tid of the current thread.
	 */
	int hilolay_get_tid(void);

	/**
	 * Does a wait operation over a semaphore. It blocks the thread if no resources available.
	 */
	int hilolay_wait(char *sem_name);

	/**
	 * Does a signal operation over a semaphore.
	 */
	int hilolay_signal(char *sem_name);
#endif // hilolay_h__
