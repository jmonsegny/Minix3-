#pragma once

#include <proc.h>
#include <message.h>

// Base virtual class
class Call
{
public:
    virtual int operator()(Proc& caller, Message& mess) = 0;
};

// Process management classes
class CallDoFork : public Call
{
public:
	int operator()(Proc& caller, Message& mess) override;
};

class CallDoExec : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoClear : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoExit : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoPrivCtl : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoTrace : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoSetGrant : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoRunCtl : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoUpdate : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoStateCtl : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

// Signal handling classes
class CallDoKill : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoGetKSig : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoEndKSig : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoSigSend : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoSigReturn : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

// Device IO classes
class CallDoIRQCtl : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoDevIO : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoVDevIO : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

// Memory management classes
class CallDoMemset : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoVMCtl : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

// Copying classes
class CallDoUMap : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoUMapRemote : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoVUMap : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoVirCopy : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoCopy : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoSafeCopyFrom : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoSafeCopyTo : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoVSafeCopy : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

// Safe memset class
class CallDoSafeMemset : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

// Clock functionality classes
class CallDoTimes : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoSetAlarm : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoSTime : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoSetTime : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoVTimer : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

// System control classes
class CallDoAbort : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoGetInfo : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoDiagCtl : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

// Profiling class
class CallDoSProfile : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

// i386 specific classes
class CallDoReadBios : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoIOpenTable : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoSDevIO : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

// Machine state switching classes
class CallDoSetmContext : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoGetmContext : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

// Schedulling classes
class CallDoSchedule : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};

class CallDoSchedCtl : public Call
{
public:
    int operator()(Proc& caller, Message& mess) override;
};
