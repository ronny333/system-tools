#
set -x
set -e
../tcpforward/tcpforward 5003:15.9.72.108:5003 23:192.168.1.159:23 80:192.168.1.159:80 554:192.168.1.159:554 8899:192.168.1.159:8899 34567:192.168.1.159:34567
