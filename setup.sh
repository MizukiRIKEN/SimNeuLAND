#!/bin/bash

#------> added for setting up the GEANT4
source /usr/local/lib64/geant4.9.6.p04/share/Geant4-9.6.4/geant4make/geant4make.sh
export TARTSYS=/home/kondo/exp/samurai21/anaroot/src
#<------


export SMSIMDIR=$PWD
export PATH=$PATH:$SMSIMDIR/bin/Linux-g++
export G4SMLIBDIR=$SMSIMDIR/smg4lib

export G4SMPHYSICSDIR=$SMSIMDIR/smg4lib/physics
export G4SMACTIONDIR=$SMSIMDIR/smg4lib/action
export G4SMCONSTRUCTIONDIR=$SMSIMDIR/smg4lib/construction
export G4SMDATADIR=$SMSIMDIR/smg4lib/data

export G4SMCPPFLAGS="-I$G4SMLIBDIR/include"
export G4SMLDLIBS="-lsmphysics -lsmaction -lsmconstruction -lsmdata"


    echo $LD_LIBRARY_PATH
    echo
    echo $G4SMLIBDIR
    echo
    echo $SMSIMDIR


if [[ $LD_LIBRARY_PATH == "" ]]; then
    export LD_LIBRARY_PATH=$G4SMLIBDIR/lib:$SMSIMDIR/lib:$TARTSYS/lib
else
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$G4SMLIBDIR/lib:$SMSIMDIR/lib:$TARTSYS/lib
fi

if [[ $LIBRARY_PATH == "" ]]; then
    export LIBRARY_PATH=$G4SMLIBDIR/lib
else
    export LIBRARY_PATH=$LIBRARY_PATH:$G4SMLIBDIR/lib
fi

## ----> for kondo
#export G4VRMLFILE_VIEWER=view3dscene
#export PATH=$PATH:/home/kondo/exp/geant4/viewer/bin:$TARTSYS/../util/bin
#export TANASYS=/home/kondo/exp/samurai21/anaroot/mysrc
#export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$TANASYS/lib
#export LIBRARY_PATH=$LIBRARY_PATH:$TANASYS/lib
