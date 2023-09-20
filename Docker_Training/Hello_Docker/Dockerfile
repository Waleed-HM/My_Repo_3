# Fetch ubuntu image
FROM ubuntu:22.04

# Install Python on image
# The RUN command essentially runs some command on the OS running in the docker image
# The slash (\) tells docker that the command continues in the next line
RUN \
	apt-get update && \
	apt-get install -y python3

# Create a directory for out tests
RUN mkdir /tests

# Copy in our Python script
# The COPY command copies something from our local directory (where docker file is) into the image
COPY test.py /tests/test.py

# Often times, when we create a container, we want it to automatically run some application or test .. etc
# This command that will be invoked when container starts
# It's as if we are running this command (python3 tests/test.py) on ubuntu
ENTRYPOINT ["python3", "tests/test.py"]

# Note : sometimes we might see something like : (CMD ["something", "else"]) after the previous line
# That would mean it becomes something like this : $ python3 tests/test.py something else
# If we don't provide ENTRYPOINT, docker uses a default one : $ /bin/sh -c something else (when CMD is used)
# Or just : $ /bin/sh -c , if nothing is supplied


# Notes :
# To build the docker image, run in the terminal :
# docker build -t [image name] .
# To view images : docker images
# To create the docker container based on the image, we run the command :
# docker create -i -t --entrypoint="/bin/bash" --name my_container my_image

# i : interactive mode, keep the container running and allow interactions
# t : tty : adds a pseudo terminal for command line interaction
# entrypoint : to override any ENTRYPOINT command in the docker file, in this case we want it to run bash instead of out python script
# name : to give the container a name
# my_image : which image to create the container from

# To list the available containers :
# docker container ls -a