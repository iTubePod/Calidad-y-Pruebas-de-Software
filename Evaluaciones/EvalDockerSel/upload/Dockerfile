FROM tutum/apache-php

WORKDIR /app

RUN apt-get update

RUN apt-get -y install mysql-server

COPY . /app
