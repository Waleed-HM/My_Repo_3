import os, subprocess

# Settings
PROJECT_DIR = "."
CODE_DIR = "src"
CODE_FILE = "main.cpp"
APP_DIR = "output"
APP_FILE = "app"
COMPILER_TIMEOUT = 10.0
RUN_TIMEOUT = 10.0

# Create absolute paths
code_path = os.path.join(PROJECT_DIR,CODE_DIR,CODE_FILE)
app_path = os.path.join(PROJECT_DIR,APP_DIR,APP_FILE)

# Compile the program
print("Building ..")

try:
	os.chdir("/home/runner/work/My_Repo_3/My_Repo_3/CPP_Training/002Bank_Account")
	ret = subprocess.run(["make"],
							stdout=subprocess.PIPE,
							stderr=subprocess.PIPE,
							timeout=COMPILER_TIMEOUT)
except Exception as e:
	print("Error : Compilation failed !",str(e))
	exit(1)

# Parse the output
output = ret.stdout.decode('utf-8')
print(output)
output = ret.stderr.decode('utf-8')
print(output)

# Check to see if the program compiled successfully
if ret.returncode != 0:
	print("Compilation failed !")
	exit(1)

# Run the compiled program
print("Running the project ..")
try:
	os.chdir("/home/runner/work/My_Repo_3/My_Repo_3/CPP_Training/002Bank_Account")
	ret = subprocess.run(["make", "execute"],
							stdout=subprocess.PIPE,
							timeout=RUN_TIMEOUT)

except Exception as e:
	print("ERROR : Runtime failed !",str(e))
	exit(1)

# Parse output
output = ret.stdout.decode('utf-8')
print("Project output : \n")
print(output)
output = ret.stderr.decode('utf-8')
print(output)

# print("Program ran successfully !")

# Clean everything
print("Cleaning the project !")
os.chdir("/home/runner/work/My_Repo_3/My_Repo_3/CPP_Training/002Bank_Account")
ret = subprocess.run(["make","clean"],
						stdout=subprocess.PIPE)

# Parse cleaning output
output = ret.stdout.decode('utf-8')
print(output)

# Exit gracefully
print("Finishing !")
exit(0)