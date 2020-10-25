#!usr/bin/env python
import subprocess
import optparse


def get_arguments():
    parser = optparse.OptionParser()
    parser.add_option("-i", "--interface", dest="interface", help="Interface to change required")
    parser.add_option("-m", "--mac", dest="mac", help="this is your new mac address")
    (options, arguments) = parser.parse_args()
    if not options.interface:
        parser.error("Please specify the interface, use --help for info")
    elif not options.mac:
        parser.error("Please specify the mac address, use --help for info")
    return options


def mac_changer(interface, mac):
    subprocess.call(["sudo", "ifconfig", interface, "down"])
    subprocess.call(["sudo", "ifconfig", interface, "hw", "ether", mac])
    subprocess.call(["sudo", "ifconfig", interface, "up"])
    subprocess.call(["sudo", "ifconfig", interface])


option = get_arguments()
interface = option.interface
mac = option.mac
mac_changer(interface, mac)