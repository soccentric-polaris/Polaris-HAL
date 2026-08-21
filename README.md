# Polaris-HAL

## Project Summary

- Polaris-HAL is the C++ hardware-abstraction layer for Polaris boards. It
  combines a generated and protocol-defined gRPC boundary under `protos/`
  with one library directory per hardware capability under `src/`. The
  protocol set includes common messages, client and HAL services, a module
  registry, and typed module definitions for CPU, GPU, storage, thermal,
  networking, cameras, audio, GPIO, sensors, safety, connectivity, and
  specialized peripherals. The server side contains the HAL service
  implementation and typed module handler; the client side provides a
  reusable gRPC client for callers such as Polaris-Client.

- Each capability library follows the repository CMake structure and exposes
  a small C++ interface. The codebase includes platform constants and
  registry data, Docker build/package helpers, Doxygen configuration,
  formatting and cppcheck targets, and deployment-oriented Make targets.
  This is a substantial implementation surface, but hardware behavior
  depends on device nodes, kernel drivers, and the actual Polaris board. A
  source-level library or test executable is not proof that a peripheral is
  present or that an operation succeeds on target hardware.

- Automated evidence is strongest in the per-module test tree: CMake-backed
  test programs exist for most listed libraries, including CPU, GPU,
  camera, video, Ethernet, USB, power, safety, reliability, storage, and
  system functions. The repository also has a shared test runner and CMake
  test wiring. The root Makefile declares native/container builds, package
  targets, `test`, `format`, `cppcheck`, and `doc`; Docker is the default
  path for the checked-in workflow. The inventory distinguishes
  protocol/library presence from real-board validation.

## Feature Inventory

| # | Name / Description | Implemented? | Test Coverage? | Manual Test |
|---:|---|---|---|---|
| 1 | Common protobuf types and HAL/client services | Implemented | Protocol CMake wiring; service integration partial | [ ] Manual verification required |
| 2 | gRPC HAL server and typed module handler | Implemented | Service test executables present; depth varies | [ ] Manual verification required |
| 3 | gRPC HAL client | Implemented | No dedicated client assertion suite found | [ ] Manual verification required |
| 4 | Module registry and generated module list | Implemented | Registry sources/tests present | [ ] Manual verification required |
| 5 | Compute libraries: CPU, GPU, DLA, vision accelerator | Implemented | Per-module test programs found | [ ] Manual verification required |
| 6 | Camera, display, video, and audio libraries | Implemented | Per-module tests found | [ ] Manual verification required |
| 7 | Networking and connectivity: Ethernet, switch, USB, PCIe | Implemented | Per-module tests found | [ ] Manual verification required |
| 8 | GPIO, IMU, GNSS, environmental, and timing modules | Implemented | Per-module tests found | [ ] Manual verification required |
| 9 | Storage, memory, power, thermal, watchdog | Implemented | Per-module tests found | [ ] Manual verification required |
| 10 | Safety, reliability, security, and debug modules | Implemented | Per-module tests found | [ ] Manual verification required |
| 11 | Platform-specific device access and constants | Partial | Test executables exist; target matrix not found | [ ] Manual verification required |
| 12 | Docker cross-build and package workflows | Implemented | Make targets declared; image execution unverified | [ ] Manual verification required |
| 13 | Doxygen, clang-format, and cppcheck integration | Implemented | Targets declared; reports not inspected | [ ] Manual verification required |

## Validation

```bash
make docker-build
make test
make format
make cppcheck
```

Run module tests on a supported board to validate drivers, permissions, timing, and physical peripherals.
