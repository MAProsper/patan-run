#!/usr/bin/env bash -i

err() { echo "$*"; exit 1; }
shell() { "$SHELL" -ic "$*" &>'/dev/null'; }
chk() { shell 'type patan-run'; echo "$?"; }

[ $# -eq 2 ] || err 'file alXXXXXX'
[ -f "$1" ] || err 'file not found'
[ -n "$2" ] || err 'user not defined'
export RUN="$1" USER="$2"

shell 'patan-run remove'; chk
shell 'bash "$RUN" "$USER" install'; chk
shell 'patan-run remove'; chk
shell 'bash "$RUN" "$USER" install'; chk
