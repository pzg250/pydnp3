/*
 * -*- coding: utf-8 -*- {{{
 * vim: set fenc=utf-8 ft=python sw=4 ts=4 sts=4 et:
 *
 * Copyright 2018, Kisensum.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Neither Kisensum, nor any of its employees, nor any jurisdiction or
 * organization that has cooperated in the development of these materials,
 * makes any warranty, express or implied, or assumes any legal liability
 * or responsibility for the accuracy, completeness, or usefulness or any
 * information, apparatus, product, software, or process disclosed, or
 * represents that its use would not infringe privately owned rights.
 * Reference herein to any specific commercial product, process, or service
 * by trade name, trademark, manufacturer, or otherwise does not necessarily
 * constitute or imply its endorsement, recommendation, or favoring by Kisensum.
 * }}}
 */

#include <pybind11/pybind11.h>
#include <python2.7/Python.h>

#include <openpal/logging/StringFormatting.h>

namespace py = pybind11;

void bind_StringFormatting(py::module &m)
{
    // ----- const: openpal::MAX_LOG_ENTRY_SIZE -----
	m.attr("MAX_LOG_ENTRY_SIZE") = &openpal::MAX_LOG_ENTRY_SIZE;

	// ----- const: openpal::MAX_HEX_PER_LINE -----
	m.attr("MAX_HEX_PER_LINE") = &openpal::MAX_HEX_PER_LINE;

	// ----- func: openpal::LogHex -----
	m.def(
	    "LogHex",
	    &openpal::LogHex,
	    ":type firstRowSize: unsigned int \n"
	    ":type otherRowSize: unsigned int",
	    py::arg("logger"), py::arg("filters"), py::arg("source"), py::arg("firstRowSize"), py::arg("otherRowSize")
	);

	// ----- func: openpal::AllocateCopy -----
	m.def(
	    "AllocateCopy",
	    &openpal::AllocateCopy,
	    "Portable allocation of a copy of a cstring.",
	    py::arg("alias")
	);
}