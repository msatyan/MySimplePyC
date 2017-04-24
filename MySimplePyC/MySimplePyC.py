import MyCExtnMod1


def Main():
	rc = MyCExtnMod1.MyPyfunc1("Hello From Python")
	print('The Pyhon has recieved {:d} from C function'.format(rc))

if __name__ == "__main__":
    Main()
else:
    print("one.py is being imported into another module")

