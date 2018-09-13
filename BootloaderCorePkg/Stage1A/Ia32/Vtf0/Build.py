## @file
#  Automate the process of building the various reset vector types
#
#  Copyright (c) 2009 - 2017, Intel Corporation. All rights reserved.<BR>
#
#  This program and the accompanying materials
#  are licensed and made available under the terms and conditions of the BSD License
#  which accompanies this distribution.  The full text of the license may be found at
#  http://opensource.org/licenses/bsd-license.php
#
#  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
#  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#

import glob
import os
import subprocess
import sys

def RunCommand(commandLine):
    return subprocess.call(commandLine)

def FixupForRawSection(sectionFile):
    d = open(sectionFile, 'rb').read()
    c = ((len(d) + 4 + 7) & ~7) - 4
    if c > len(d):
        c -= len(d)
        f = open(sectionFile, 'wb')
        f.write('\x90' * c)
        f.write(d)
        f.close()

for filename in glob.glob(os.path.join('Bin', '*.raw')):
    os.remove(filename)

if 1:
    if 1:
        arch = 'ia32'
        debugType = None
        output = os.path.join('Bin', 'ResetVector')
        output += '.' + arch
        if debugType is not None:
            output += '.' + debugType
        output += '.raw'
        nasmpath = os.path.join(os.environ.get ('NASM_PREFIX', ''), 'nasm')
        commandLine = (
            nasmpath,
            '-D', 'ARCH_%s' % arch.upper(),
            '-D', 'DEBUG_%s' % str(debugType).upper(),
            '-o', output,
            'Vtf0.nasmb',
            )
        ret = RunCommand(commandLine)
        print '\tASM\t' + output
        if ret != 0: sys.exit(ret)

        FixupForRawSection(output)
        print '\tFIXUP\t' + output


