#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "sandbox.h"

typedef struct pool_impl {

}

typedef struct isnt_impl {
	pthread_t thread;
}

void poolclose(sandbox_pool* pool) {
	void** ptrs = malloc(sizeof(void*) * pool->inst_amt);
	memcpy(ptrs, pool->instances, pool->inst_amt);
	size_t t;
	for (t = 0; t < pool->inst_amt; t++) {
		instclose(ptrs[t]);
	}
	free(pool->internal);
	free(pool);
}

void instclose(sandbox_inst* inst) {

	if (inst->pool->inst_amt == 1) {
		free(inst->pool->instances);
		inst->pool->instances = 0;
	}
	else {
		uint8_t valid = 0;
		size_t t;
		for (t = 0; t < inst->pool->inst_amt; t++) {
			if (inst->pool->instances[t] == inst) {
				valid = 1;
				break;
			}
		}

		// instance isn't registered in it's own pool, probably means it was closed already
		if (!valid) {
			return 1;
		}

		if (t != inst->pool->inst_amt) {
			sandbox_inst* ptr = (sandbox_inst*) inst->pool->instances;
			memmove(ptr + t, ptr + (t + 1), inst->pool->inst_amt - (t + 1));
		}
		else {
			inst->pool->instancs = realloc(inst->pool->instances, inst->pool->inst_amt - 1);
		}
		inst->pool->inst_amt--;

		//TODO: thread exit w/ pthreads

		free(inst->internal);
		free(inst);
	}
	return 0;
}

void regcallback(sandbox_pool* pool, char* identifier, void (*func_ptr) ()) {

}

void pass(struct _sandbox_inst* self, uint8_t* prgm, size_t prgm_size, void (*callback) (int8_t response)) {

}

void entry(void* param) {

}

sandbox_pool* init(int8_t* cores, size_t cores_size) {
	sandbox_pool* pool = malloc(sizeof(sandbox_pool));
	pool->close = &poolclose;
	pool->inst_amt = 0;
	pool->internal = malloc(sizeof(pool_impl));
	return pool;
}

sandbox_inst* newinst(sandbox_pool* pool, int heapsize) {
	sandbox_inst* inst = malloc(sizeof(sandbox_inst));
	inst->heapsize = heapsize;
	inst->close = &instclose;
	inst->pass = &pass;
	inst->pool = pool;
	inst->internal = malloc(sizeof(inst_impl));

	if (pool->inst_amt == 0) {
		pool->instances = malloc(sizeof(void*));
	}
	else {
		pool->instances = realloc(pool->instances, pool->inst_amt + 1);
	}
	pool->instances[inst_amt] = inst;
	pool->inst_amt++;

	//TODO: thread entry w/ pthreads

	return inst;
}

void sandbox_init() {
	void (*sandbox_regcallback) (sandbox_pool*, char*, void (*ptr) ()) = &regcallback;
	sandbox_pool* (*sandbox_init) (int8_t*, size_t) = &init;
	sandbox_inst* (*sandbox_newinst) (sandbox_pool*, int) = &newinst;
	return;
}

void sandbox_fini() {

}