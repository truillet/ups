import sys
from datetime import datetime
from scapy.all import srp,Ether, ARP, conf 

try:
	interface = raw_input("[*] Enter Desired Interface: ") # Get interface to scan
	ips = raw_input("[*] Enter Range of IPs to scan for: ") #Get IP range to scan

except KeyboardInterrupt:
	print "\n[*] User Requested Shutdown"
	print "[*] Quitting..."
	sys.exit(1)

print "\n[*] Scanning..." #Initiate scannig
start_time = datetime.now() # start clock for time duration

conf.verb = 0  #Actually start scanning
ans, unans = srp(Ether(dst="ff:ff:ff:ff:ff:ff")/ARP(pdst = ips), timeout = 2, iface=interface,inter=0.1)

print "MAC - IP\n" # set up for result display
for snd, rcv in ans:
	print rcv.sprintf(r"%Ether.src% - %ARP.psrc%") # display results
stop_time = datetime.now() # stop clock for total duraction
total_time = stop_time - start_time #found total time

print "\n[*] Scan Complete!" #confirm scan completion
print ("[*] Scan Duration: %s" %(total_time)) # display scan duration

