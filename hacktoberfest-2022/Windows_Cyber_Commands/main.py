# Coded by SpiderX

# Modules
import os
import time

# Logo and Front-End
from intro import *
intro1()

while True:
    try:
        ui = int(input("\nEnter your choice :"))
        if ui == 1:
            print("Getting Computer's IP Setting... \n")
            time.sleep(1)
            os.system("ipconfig")

        elif ui == 2:
            print("\n Hit the Website Address..."
                  "\n \t ex: www.facebook.com")
            web = input("Leave the Address : ")
            print("Hitting the IP Address")
            os.system(f"ping {web}")

        elif ui == 3:
            print("\n Give the Website to trace..."
                  "\n \t ex: www.facebook.com")
            web = input("Leave the Address : ")
            print("Tracing the Website...")
            time.sleep(1)
            os.system(f"tracert {web}")

        elif ui == 4:
            print("\n Give the Website to trace..."
                  "\n \t ex: www.facebook.com")
            web = input("Leave the Address : ")
            print("Tracing to the Deep...")
            os.system(f"pathping {web}")

        elif ui == 5:
            print("Getting the Arp Table...")
            os.system("arp -a")

        elif ui == 6:
            print("\n Give the Website to Check DNS..."
                  "\n \t ex: www.facebook.com")
            web = input("\n Leave the address :")
            print("\n Getting DNS... ")
            os.system(f"nslookup {web}")

        elif ui == 7:
            print("\n Manipulating Network Routing Tables... ")
            os.system("route print")

        elif ui == 8:
            print("\n Getting all Open Connections... ")
            os.system("netstat -an")

        elif ui == 9:
            print("\n Getting detailed TCP/IP info... ")
            os.system("ipconfig/all")

        elif ui == 10:
            print("Repairing...")
            os.system("sfc /scannow")

        elif ui == 404:
            BRIDGE()
            break

        elif ui == 999:
            from intro import *
            intro1()

        else:
            from intro import *
            intro1()

    except Exception as e:
        print(e)
