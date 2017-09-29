FROM openjdk:8

RUN apt-get update \
  && apt-get install --yes \
  build-essential \
  scons

RUN curl \
  --silent \
  --location \
  https://bootstrap.pypa.io/get-pip.py \
  --output /tmp/get-pip.py \
  && python /tmp/get-pip.py

RUN pip install \
  pipenv

RUN apt-get clean \
  && rm -rf /var/lib/apt/lists/* \
  && rm -rf /tmp/* \
  && rm -rf /var/tmp/*
