# Use Debian Bookworm as the base image
FROM debian:bookworm-slim

# Install required tools and dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    fish \
    cmake \
    gdb \
    git \
    exuberant-ctags \
    cscope \
    clang-format \
    vim \
    tmux \
    locales \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Set locale (optional but recommended)
RUN sed -i '/en_US.UTF-8/s/^# //' /etc/locale.gen && \
    locale-gen
ENV LANG=en_US.UTF-8
ENV LANGUAGE=en_US:en
ENV LC_ALL=en_US.UTF-8

# Set fish as default shell
RUN echo /usr/bin/fish >> /etc/shells && chsh -s /usr/bin/fish root

# Copy your local config files
COPY .devcontainer/config/vimrc /root/.vimrc
COPY .devcontainer/config/tmux.conf /root/.tmux.conf
COPY .devcontainer/config/clang-format /workspace/.clang-format

# Set the working directory
WORKDIR /workspace

# Default command
CMD ["tmux"]
