/* 
TEST_HEADER
 id = $Id$
 summary = -1 rank for mps_root_create
 language = c
 link = testlib.o
OUTPUT_SPEC
 assert = true
 assertfile P= ref.c
 assertcond = rank < RankLIMIT
END_HEADER
*/

#include "testlib.h"
#include "arg.h"

static mps_res_t rootscan(mps_ss_t ss, void *p, size_t s)
{
 return MPS_RES_OK;
}

static void test(void *stack_pointer)
{
 mps_arena_t arena;
 mps_thr_t thread;
 mps_root_t root;

 cdie(mps_arena_create(&arena, mps_arena_class_vm(), mmqaArenaSIZE), "create arena");

 cdie(mps_thread_reg(&thread, arena), "register thread");

 cdie(mps_root_create(&root, arena, -1, 0,
                      rootscan, NULL, 0),
      "root create");

}

int main(void)
{
 run_test(test);
 return 0;
}
