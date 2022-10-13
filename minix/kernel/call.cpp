#include <call.h>
#include <arch/i386/direct_tty_utils.h>

// Process management classes
int CallDoFork::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_fork\n");
	return 0;
}

int CallDoExec::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_fork\n");
    return 0;
}

int CallDoClear::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_fork\n");
    return 0;
}

int CallDoExit::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_fork\n");
    return 0;
}

int CallDoPrivCtl::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_fork\n");
    return 0;
}

int CallDoTrace::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_fork\n");
    return 0;
}

int CallDoSetGrant::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_fork\n");
    return 0;
}

int CallDoRunCtl::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_fork\n");
    return 0;
}

int CallDoUpdate::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_update\n");
    return 0;
}

int CallDoStateCtl::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_fork\n");
    return 0;
}

// Signal handling classes
int CallDoKill::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_kill\n");
    return 0;
}

int CallDoGetKSig::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_getksig\n");
    return 0;
}

int CallDoEndKSig::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_endksig\n");
    return 0;
}

int CallDoSigSend::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_sigreturn\n");
    return 0;
}

int CallDoSigReturn::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_sigreturn\n");
    return 0;
}


// Device IO classes
int CallDoIRQCtl::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_irqctl\n");
    return 0;
}

int CallDoDevIO::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_devio\n");
    return 0;
}

int CallDoVDevIO::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_vdevio\n");
    return 0;
}

// Memory management classes
int CallDoMemset::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_memset\n");
    return 0;
}

int CallDoVMCtl::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_vmctl\n");
    return 0;
}

int CallDoUMap::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_umap\n");
    return 0;
}

int CallDoUMapRemote::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_umap_remote\n");
    return 0;
}

int CallDoVUMap::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_vumap\n");
    return 0;
}

int CallDoVirCopy::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_vircopy\n");
    return 0;
}

int CallDoCopy::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_copy\n");
    return 0;
}

int CallDoSafeCopyFrom::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_safecopy_from\n");
    return 0;
}

int CallDoSafeCopyTo::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_safecopy_to\n");
    return 0;
}

int CallDoVSafeCopy::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_vsafecopy\n");
    return 0;
}

// Safe memset class
int CallDoSafeMemset::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_safememset\n");
    return 0;
}

// Clock functionality class
int CallDoTimes::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_times\n");
    return 0;
}

int CallDoSetAlarm::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_setalarm\n");
    return 0;
}

int CallDoSTime::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_stime\n");
    return 0;
}

int CallDoSetTime::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_settime\n");
    return 0;
}

int CallDoVTimer::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_vtimer\n");
    return 0;
}

// System controll classes
int CallDoAbort::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_abort\n");
    return 0;
}

int CallDoGetInfo::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_getinfo\n");
    return 0;
}

int CallDoDiagCtl::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_diagctl\n");
    return 0;
}

// Profiling class
int CallDoSProfile::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_sprofile\n");
    return 0;
}

// i386 specific classes
int CallDoReadBios::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_readbios\n");
    return 0;
}

int CallDoIOpenTable::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_iopentable\n");
    return 0;
}

int CallDoSDevIO::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_sdevio\n");
    return 0;
}

// Machine state switching classes
int CallDoSetmContext::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_setmcontext\n");
    return 0;
}

int CallDoGetmContext::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_getmcontext\n");
    return 0;
}

// Scheduling classes
int CallDoSchedule::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_schedule\n");
    return 0;
}

int CallDoSchedCtl::
operator()(Proc& caller, Message& mess )
{
    kprintf("Printing inside do_schedctl\n");
    return 0;
}

