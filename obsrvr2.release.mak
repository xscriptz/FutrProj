###########################################################
# Makefile generated by xIDE for uEnergy                   
#                                                          
# Project: obsrvr2
# Configuration: Release
# Generated: Sun May 15 19:09:28 2016
#                                                          
# WARNING: Do not edit this file. Any changes will be lost 
#          when the project is rebuilt.                    
#                                                          
###########################################################

XIDE_PROJECT=obsrvr2
XIDE_CONFIG=Release
OUTPUT=obsrvr2
OUTDIR=C:/CSR_uEnergy_SDK-2.6.0.10/apps/obsrvr2
DEFS=

OUTPUT_TYPE=0
USE_FLASH=0
ERASE_NVM=1
CSFILE_CSR101x_A05=
MASTER_DB=
LIBPATHS=
INCPATHS=
STRIP_SYMBOLS=0
OTAU_BOOTLOADER=0
OTAU_CSFILE=
OTAU_NAME=
OTAU_SECRET=
OTAU_VERSION=7

DBS=


INPUTS=\
      main.c\
      $(DBS)

KEYR=


-include obsrvr2.mak
include $(SDK)/genmakefile.uenergy
