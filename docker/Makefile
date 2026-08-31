IMAGE_NAME ?= polaris

.PHONY: build run clean delete-images

build:
	@echo "Building Docker image $(IMAGE_NAME) for Polaris Platform (ARM64)..."
	docker buildx build --platform linux/arm64 --load --build-arg UID=$(shell id -u) --build-arg GID=$(shell id -g) -t $(IMAGE_NAME) .

run:
	# No --gpus flag: Renesas RZ/G2L has Renesas RZ/G2L (not CUDA)
	docker run -it --rm --hostname "Renesas RZ/G2L" $(IMAGE_NAME)

clean:
	docker rmi $(IMAGE_NAME) || true

delete-images:
	docker rmi $(docker images -q) || true
