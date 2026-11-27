# Polaris-HAL Build and Deployment

## Purpose and scope

Polaris-HAL is a CMake/Ninja C++ hardware-abstraction test suite. Its Makefile supports native builds, ARM64 Docker/QEMU builds, CTest, CPack packages, quality checks, Doxygen, and deployment to Raspberry Pi 5-class targets.

## 1. Prerequisites

- Linux, GNU Make, CMake, Ninja, a C++ compiler, `nproc`, and CTest.
- Docker with ARM64 emulation for cross targets; `make docker-install` can install Docker using `sudo apt`.
- `clang-format`, `cmake-format`, `cppcheck`, `doxygen`, and Graphviz for optional quality/documentation targets.
- `sshpass`, network reachability, and target credentials for deployment. Override `IP_A`, `IP_B`, `USER`, `PASS` or `HAL_SSH_USER`/`HAL_SSH_PASS`; do not use real passwords in shell history where policy forbids it.

## 2. Setup

```bash
make configure
make docker-image
```

Native configuration creates `build/native`; Docker configuration uses `build/cross` and the `polaris` image.

## 3. Build and compile

```bash
make build                  # native CMake/Ninja
make docker-configure
make docker-build           # ARM64 Docker/Ninja
```

The default `make` target is `docker-build`. Override `JOBS=N` for parallelism. Docker uses the `polaris` image and an ARM64 platform.

## 4. Test and lint

```bash
make test                   # native CTest
make docker-test            # CTest under ARM64/QEMU
make format
make cppcheck
make doc
```

The quality targets check for their required tools before running generated Ninja targets.

## 5. Packaging and artifacts

```bash
make package-deb           # native DEB in build/native
make package-rpm           # native RPM; requires rpmbuild
make package-ipk           # native IPK
make package               # DEB + IPK
make docker-package-deb
make docker-package-rpm
make docker-package-ipk
make docker-package         # cross DEB + IPK
```

Native packages are emitted by CPack in `build/native`; cross packages are generated in `build/cross`. Exact filenames are printed by the targets and depend on project versioning.

## 6. Deployment, install, and run

```bash
HAL_SSH_USER=root HAL_SSH_PASS='REDACTED' make deploy-a
make deploy-b
make run-a [app] [args...]
make run-b [app] [args...]
make run [app] [args...]   # local native execution
```

Deployment first cross-builds, then replaces `/tmp/acu-test` on the selected target and copies `build/cross/lib` and `build/cross/bin`. These targets require hardware, credentials, and correct IPs; `run-*` executes every binary when no app is supplied.

## 7. Cleanup

```bash
make clean
make docker-clean
```

The first removes both build directories. The second removes the Docker-side cross build but retains the image and ccache volume.

## 8. Verification caveats

Builds and CTest do not prove HAL behavior on a physical board. Manually verify device permissions, ABI compatibility, peripheral access, target boot/runtime behavior, and package installation. No cloud deployment is declared.