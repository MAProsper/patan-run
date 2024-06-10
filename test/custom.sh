#!/usr/custom
# [args...]
# 	args	...	(program arguments)
job

#!/job/custom
info "$@"
IFS='' read -rp 'n = ' 'line'
info "$line"
