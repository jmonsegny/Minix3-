#include <call.h>
#include <arch/i386/direct_tty_utils.h>

int CallDoFork::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_fork\n");
}

