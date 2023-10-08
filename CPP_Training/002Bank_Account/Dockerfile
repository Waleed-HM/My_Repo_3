# Fetch ubuntu image
From ubuntu:22.04

# Install build tools
RUN apt update && \
	apt install -y wget build-essential autoconf automake libtool

# Copy project into image
RUN mkdir /Bank_Account
COPY src /Bank_Account/src
COPY inc /Bank_Account/inc
COPY tests /Bank_Account/tests
COPY Makefile /Bank_Account/Makefile

# Download and build Cpputest
RUN mkdir /Bank_Account/tools/ && \
	cd /Bank_Account/ && \
	wget https://github.com/cpputest/cpputest/releases/download/v4.0/cpputest-4.0.tar.gz && \
	tar xf cpputest-4.0.tar.gz && \
	mv cpputest-4.0/ tools/cpputest-4.0 && \
	cd tools/cpputest-4.0 && \
	autoreconf -i && \
	./configure && \
	make

# Execute script
ENTRYPOINT ["make", "test", "-C", "/Bank_Account/", "CPPUTEST_HOME_SUFFIX=tools/cpputest-4.0"]

# To build the image, we can run:
# docker build -t bank_account -f Dockerfile .

# To run a temporary container:
# docker run --rm bank_account