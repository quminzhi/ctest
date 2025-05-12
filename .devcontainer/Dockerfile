# Use Debian Bookworm as the base image
FROM debian:bookworm-slim

# Install required tools and dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    gdb \
    git \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /workspace

# Default command
CMD ["/bin/bash"]