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


###FINAL OBSERVATION

####Output in terms of number of packets captured : 
	Channel 1 received total 714 packets
	Channel 2 received total 84 packets
	Channel 3 received total 34 packets
	Channel 4 received total 86 packets
	Channel 5 received total 62 packets
	Channel 6 received total 13 packets
	Channel 7 received total 0 packets
	Channel 8 received total 25 packets
	Channel 9 received total 22 packets
	Channel 10 received total 832 packets
	Channel 11 received total 3467 packets
	Channel 12 received total 231 packets
	Channel 13 received total 19 packets

####Across all channels : 
	Mac_id 00:B7:55:9C:D9:D2 has appeared 0.230769 times per minute
	Mac_id 00:EE:BD:8B:E6:EA has appeared 0.846154 times per minute
	Mac_id 14:1A:A3:92:94:97 has appeared 1.15385 times per minute
	Mac_id 14:30:C6:CA:C0:8E has appeared 0.153846 times per minute
	Mac_id 1C:3E:84:63:58:4B has appeared 0.0769231 times per minute
	Mac_id 24:FD:52:B1:95:F1 has appeared 40.0769 times per minute
	Mac_id 24:FD:52:F9:6A:74 has appeared 0.615385 times per minute
	Mac_id 2C:8A:72:95:F2:12 has appeared 0.384615 times per minute
	Mac_id 2C:D0:5A:38:E0:3F has appeared 0.0769231 times per minute
	Mac_id 3C:77:E6:54:6F:F6 has appeared 0.0769231 times per minute
	Mac_id 48:D2:24:AD:22:9F has appeared 1.38462 times per minute
	Mac_id 50:B6:71:56:FD:52 has appeared 2.69231 times per minute
	Mac_id 52:18:8B:B9:27:3B has appeared 24.2308 times per minute
	Mac_id 56:5A:04:50:1B:8E has appeared 13.0769 times per minute
	Mac_id 56:FD:52:B1:95:F1 has appeared 0.846154 times per minute
	Mac_id 56:FD:52:F9:6A:74 has appeared 34.6154 times per minute
	Mac_id 5E:84:DC:CB:C2:77 has appeared 0.0769231 times per minute
	Mac_id 62:6C:66:27:87:16 has appeared 0.230769 times per minute
	Mac_id 64:5A:04:50:1B:8E has appeared 2.23077 times per minute
	Mac_id 64:5A:04:AE:42:D2 has appeared 1.23077 times per minute
	Mac_id 68:17:29:45:77:6B has appeared 1 times per minute
	Mac_id 68:5D:43:50:B6:71 has appeared 10.1538 times per minute
	Mac_id 70:18:8B:39:BE:21 has appeared 6 times per minute
	Mac_id 70:18:8B:B9:27:3B has appeared 0.692308 times per minute
	Mac_id 78:52:1A:32:09:EF has appeared 20.8462 times per minute
	Mac_id 84:63:D6:7E:C5:8C has appeared 0.692308 times per minute
	Mac_id 88:C9:D0:E5:6D:A9 has appeared 20.9231 times per minute
	Mac_id 8F:B3:90:FC:4D:D4 has appeared 0.0769231 times per minute
	Mac_id 9C:04:73:C8:EE:3D has appeared 40.4615 times per minute
	Mac_id 9C:2A:70:C9:EC:AD has appeared 1.38462 times per minute
	Mac_id 9C:41:7C:43:E3:C8 has appeared 36.3077 times per minute
	Mac_id 9C:D2:1E:43:0E:B0 has appeared 8.61538 times per minute
	Mac_id 9C:D2:1E:43:0E:B7 has appeared 0.692308 times per minute
	Mac_id A4:17:31:B1:7C:F9 has appeared 0.230769 times per minute
	Mac_id B4:52:7E:E7:BB:8C has appeared 0.384615 times per minute
	Mac_id B4:CE:F6:C6:8F:34 has appeared 0.153846 times per minute
	Mac_id B8:76:3F:C7:72:45 has appeared 0.230769 times per minute
	Mac_id B8:76:3F:ED:87:CF has appeared 0.384615 times per minute
	Mac_id B8:76:3F:F0:3F:41 has appeared 0.0769231 times per minute
	Mac_id B8:98:F7:6A:D6:4E has appeared 3.46154 times per minute
	Mac_id BC:85:56:1D:FC:E1 has appeared 1.15385 times per minute
	Mac_id BC:85:56:84:4A:BB has appeared 0.153846 times per minute
	Mac_id C8:F7:33:6D:9C:CD has appeared 0.461538 times per minute
	Mac_id CC:3A:61:B4:CE:E0 has appeared 0.384615 times per minute
	Mac_id E5:6D:A9:9C:41:7C has appeared 1.07692 times per minute
	Mac_id E7:BB:8C:F8:2F:A8 has appeared 0.153846 times per minute
	Mac_id F0:DB:E2:7B:06:E5 has appeared 0.307692 times per minute
	Mac_id F4:B7:E2:58:D9:F9 has appeared 1.61538 times per minute
	Mac_id F4:F5:A5:C2:9B:00 has appeared 1.23077 times per minute
	Mac_id F8:2F:A8:C4:5E:DF has appeared 109.538 times per minute
	Mac_id FC:4D:D4:50:51:A0 has appeared 0.384615 times per minute
	Mac_id FC:4D:D4:50:51:A1 has appeared 36.3846 times per minute

