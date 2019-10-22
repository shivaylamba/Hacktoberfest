import scapy.all as scapy
import optparse
def get_arguments():
	parser = optparse.OptionParser();
	parser.add_option("-t","--target",dest ="target", help = "target IP/ IP range");
	(options, arguments) = parser.parse_args()
	return options

def createPacket(ip):
	arp_request = scapy.ARP(pdst=ip) # create a ARP request object by scapy
	broadcast = scapy.Ether(dst= "ff:ff:ff:ff:ff:ff");# we have seit the destination
	arp_request_broadcast = broadcast/arp_request
	return(arp_request_broadcast)



def transmitPacket(packet):
	success_list,failure_list = scapy.srp(packet, timeout=1);
	return success_list;

def parseResponse(success_list):
	entries=[]
	for success in success_list:
		entry={}
		entry['ip']= success[1].psrc
		entry['mac'] = success[1].hwsrc
		entries.append(entry)
	return entries;

def printAnalysis(entries):
	print("IP\t\t\tMAC Address\n............................................");
	for element in entries:
		print(element["ip"]+"\t\t"+element['mac']+"\n");

options = get_arguments();
if (options.target != None):
	broadcast_packets = createPacket(options.target)
	success_packets = transmitPacket(broadcast_packets);
	entries =parseResponse(success_packets)
	printAnalysis(entries)