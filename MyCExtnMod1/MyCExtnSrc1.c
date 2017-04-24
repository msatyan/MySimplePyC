// Extending Python with C or C++
// https://docs.python.org/2/extending/extending.html


#include <stdio.h>
#include <stdlib.h>


// #include <Python.h> 
#ifdef _DEBUG
#undef _DEBUG
#include <python.h>
#define _DEBUG
#else
#include <python.h>
#endif


#include <structmember.h>

#include "MyCExtnSrc1.h"


// Very simple C function that takes a null-terminated string as argument and returns an integer.
static PyObject *MyCfunc1(PyObject *self, PyObject *args)
{
    const char *msg;
    int rc = 128;

    if (!PyArg_ParseTuple(args, "s", &msg))
    {
        return NULL;
    }

    printf("\nThe C module is built by using Python %s", PY_VERSION);
    printf("\nThe C module reveived [%s] from Python", msg);
    printf("\nThe C module returning %d to Python", rc);
    printf("\n");

    PyObject *ret = Py_BuildValue("i", rc);

    return ret;
}



static PyMethodDef MyModuleMethods[] = 
{
    // pattern : PyMehodName, CFunction, FFunctionType, Doc
    { "MyPyfunc1", MyCfunc1, METH_VARARGS, "My Awesome C Function" },
    { NULL, NULL, 0, NULL }
};


// https://docs.python.org/2/extending/newtypes.html
PyMODINIT_FUNC initMyCExtnMod1(void)
{
    PyObject *m = Py_InitModule3( "MyCExtnMod1", MyModuleMethods, 
        "This is a sample demo module  for Python extension by using C");

    if (m == NULL)
        return;
}




