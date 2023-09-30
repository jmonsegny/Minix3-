#pragma once

struct IrqHook 
{
    IrqHook* _next;
    int (*_handler)(IrqHook*);
    int _irq;
    int _id;
    //endpoint
    short _notify_id;
    unsigned long _policy;	
};
