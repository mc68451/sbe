#!/usr/bin/env python3
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/tools/utils/sbe-size/section-breakdown.py $
#
# OpenPOWER sbe Project
#
# Contributors Listed Below - COPYRIGHT 2018
#
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
# implied. See the License for the specific language governing
# permissions and limitations under the License.
#
# IBM_PROLOG_END_TAG

from elftools.elf.elffile import ELFFile
from os import path
from itertools import groupby
from sys import argv, stderr

with open(argv[1], "rb") as f:
    elf = ELFFile(f)

    for section in elf.iter_sections():
        if not section.name.startswith(".text") or section.header.sh_size == 0:
            continue

        print("%08x %s" % (section.header.sh_size, section.name.replace(".text.", "")))
