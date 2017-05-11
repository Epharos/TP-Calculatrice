import os

files = list()

for f in os.listdir(os.getcwd()) :
	if f.endswith('.cpp') and f != 'ma-calculatrice.cpp' :
		files.append(f[:len(f) - 4])
		os.system('g++ -c ' + f)
		print 'Compiling [' + f + ']'

command = 'g++ -std=c++11 ma-calculatrice.cpp -o main'

for n in files :
	command += ' ' + n + '.o'

print 'Executing [' + command + ']'
os.system(command)

print 'Launching ...\n\n'
os.system('./main')