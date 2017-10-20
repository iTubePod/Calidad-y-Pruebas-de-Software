FROM tutum/apache-php

RUN apk install --update \
				python \
				python-dev \
				py-pip \
		&& pip install pipenv \
		&& pip install Flask \
		&& pip install Redist \

WORKDIR /app
