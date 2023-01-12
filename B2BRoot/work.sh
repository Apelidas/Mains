#!/bi
op=$(hostnamectl | grep "Operating System" | cut -d ' ' -f5-)
ks=$(hostnamectl | grep "Kernel:" | cut -d ' ' -f14-)
arch="Architecture:\t\t$op$ks"
pp="Physical Processors:\t"`nproc --all`
vp="Virtual Processors:\t"`grep 'processor' /proc/cpuinfo | wc -l`
mu=$(free -m | awk 'NR==2{printf "Memory Usage:\t\t%s/%sMB (%.2f%%)\n", $3,$2,$3*100/$2 }')
du=$(df -h | awk '$NF=="/"{printf "Disk Usage:\t\t%d/%dGB (%s)\n", $3,$2,$5}')
cpu=$(top -n 1 | grep load |awk '{printf "CPU-Usage:\t\t%.2f%%\n", $11}')
boot=$(who -b | awk '{printf "Last Reboot:\t\t%s %s\n", $3, $4}')
lvmout="LVM-use:\t\t"
lvm=$lvm$(lsblk | grep "lvm" |wc -l)
if [ $lvm -eq 0 ]; then lvmout=$lvmout"no"; else lvmout=$lvmout"yes"; fi
acon=$("Active Connections:\t"`netstat -an | grep ESTABLISHED | wc -l`)
aus=$("Active Users:\t\t"`who | wc -l`)
ip=$(hostname -I)
ipa="IPv4 + MAC:\t\t"$ip
mac=$(ip a | grep link/ether | awk '{print $2}')
sud=$("Sudo:\t\t\t"`cat /var/log/auth.log | wc -l`)
Wall -n "$arch\n$pp\n$vp\n$mu\n$du\n$cpu\n$boot\n$lvmout\n$acon\n$aus\n$ipa$mac\n$sud"
