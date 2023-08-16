FROM ubuntu:20.04

# 環境変数を設定してインタラクティブな設定を無効化
# ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    iproute2 \
    iputils-ping \
    netcat-openbsd \
    clang \
    && rm -rf /var/lib/apt/lists/*

VOLUME /workspace

WORKDIR /workspace

# docker run --rm -it -v $(pwd):/workspace study-network

CMD ["/bin/bash"]
