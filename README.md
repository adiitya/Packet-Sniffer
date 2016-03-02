# PACKET SNIFFER -- USING LIBPCAP

### Steps before running :
	1. Switch to super user.
	2. Connect wireless device.
	3. In terminal:
		a.ifconfig interface_name down
		b.iwconfig interface_name mode monitor
		c.ifconfig interface_name up

###How it works:
	1. After connecting to the device it continuously hops between different channels.
	2. It randomly chooses another channel till that channel has spent 1 minute time in total.
	3. After a channel has complete result it prints it till result is done for each channel
	   and Finally result is obtained.


