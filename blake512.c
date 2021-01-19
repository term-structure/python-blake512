// blake512, a python library for the blake512 hash
// Copyright (C) 2021 tweqx
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#define PY_SSIZE_T_CLEAN
#include <Python.h>

// Internal implementation file from 'sphincs'
// No license provided, All rights reversed.
#include "src/sph_blake.h"

char nibble2hex(unsigned char nibble) {
  if (nibble < 10)
    return '0' + nibble;
  else
    return 'a' + nibble - 10;
}

static PyObject*
blake512_hash(PyObject *self, PyObject *args) {
  const char* data;
  Py_ssize_t len;

  if (!PyArg_ParseTuple(args, "s#", &data, &len))
    return NULL;

  sph_blake512_context ctx;
  unsigned char hash[64] = {0};

  sph_blake512_init(&ctx);
  sph_blake512(&ctx, data, len);
  sph_blake512_close(&ctx, hash);

  char hexdigest[64 * 2];
  for (unsigned int i = 0; i < 64; i++) {
    hexdigest[2*i + 0] = nibble2hex((hash[i] >> 4) & 0xf);
    hexdigest[2*i + 1] = nibble2hex((hash[i] >> 0) & 0xf);
  }

  return Py_BuildValue("s#", hexdigest, 128);
}

static PyMethodDef blake512_methods[] = {
     {"hash", blake512_hash, METH_VARARGS, "blake512 implementation"},
     {NULL, NULL, 0, NULL}
};

static struct PyModuleDef blake512_module =
{
    PyModuleDef_HEAD_INIT,
    "blake512",
    NULL,
    -1,
    blake512_methods
};

PyMODINIT_FUNC
PyInit_blake512(void) {
     return PyModule_Create(&blake512_module);
}
