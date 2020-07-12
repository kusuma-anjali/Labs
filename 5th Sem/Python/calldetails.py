class CallDetail:
	def __init__(self,sender,rec,sec,type1):
		self.sender = sender
		self.receiver = rec
		self.second = sec
		self.type1 = type1

class Util:
	def __init__(self):
		self.list_of_call_objects=None

	def parse_customer(self,list_of_call_string):
		self.list_of_call_string = list_of_call_string
		self.call_details = []
		for c in self.list_of_call_string:
			c = c.split(",")
			self.call_details.append(CallDetail(c[0],c[1],c[2],c[3]))

	def print_values(self):
		print("the caller details are: ")
		for call in self.call_details:
			print("caller id: ",call.sender,"\n","receiver id: ",call.receiver,"\n","caller time: ",call.second,"\n","type: ",call.type1)
		

call='9990000001,9330000001,23,STD'
call2='9990000001,9330000002,54,Local'
call3='9990000001,9330000003,6,ISD'
list_of_call_string=[call,call2,call3]
u = Util()
u.parse_customer(list_of_call_string)
u.print_values()


