/**
 * @file platform_polaris_rzg2l.h
 * @brief Polaris Renesas RZ/G2L platform constants.
 *
 * This header centralizes platform paths and capability values used by HAL
 * modules. Deterministic/bit-precise I/O is expected to be delegated to the
 * Cortex-M33 real-time core and controlled from Linux via remoteproc + RPMsg.
 */

#pragma once

// CPU family: dual Cortex-A55.
static constexpr int    POLARIS_RZG2L_CPU_CORES        = 2;
static constexpr double POLARIS_RZG2L_CPU_MAX_FREQ_MHZ = 1200.0;
static constexpr double POLARIS_RZG2L_CPU_MIN_FREQ_MHZ = 300.0;
static constexpr double POLARIS_RZG2L_CPU_TEMP_MAX_C   = 105.0;

// GPU: Arm Mali-G31.
static constexpr int    POLARIS_RZG2L_GPU_SHADER_CORES = 2;
static constexpr double POLARIS_RZG2L_GPU_MAX_FREQ_MHZ = 650.0;
static constexpr double POLARIS_RZG2L_GPU_MIN_FREQ_MHZ = 200.0;
static constexpr double POLARIS_RZG2L_GPU_TEMP_MAX_C   = 90.0;
static constexpr const char* POLARIS_RZG2L_GPU_DEVFREQ_PATH = "/sys/class/devfreq/";
static constexpr const char* POLARIS_RZG2L_GPU_DEVICE_PATH  = "/sys/devices/platform/";
static constexpr const char* POLARIS_RZG2L_V3D_DEV_PATH     = "/dev/dri/card0";
static constexpr const char* POLARIS_RZG2L_V3D_RENDER_PATH  = "/dev/dri/renderD128";

// Memory: DDR4 up to 2GB on SMARC module.
static constexpr long long POLARIS_RZG2L_MEM_8GB_BYTES = 8LL * 1024 * 1024 * 1024;
static constexpr long long POLARIS_RZG2L_MEM_4GB_BYTES = 4LL * 1024 * 1024 * 1024;
static constexpr double POLARIS_RZG2L_MEM_SPEED_MHZ    = 1600.0;
static constexpr double POLARIS_RZG2L_MEM_BW_GBS       = 12.8;
static constexpr int    POLARIS_RZG2L_MEM_BUS_BITS     = 32;

// PCIe: none on RZ/G2L (external via carrier only).
static constexpr int    POLARIS_RZG2L_PCIE_GEN    = 0;
static constexpr int    POLARIS_RZG2L_PCIE_LANES  = 0;
static constexpr double POLARIS_RZG2L_PCIE_BW_GBS = 0.0;
static constexpr const char* POLARIS_RZG2L_PCIE_RC_PATH = "";

// USB.
static constexpr const char* POLARIS_RZG2L_XHCI_DRIVER_PATH = "/sys/bus/platform/drivers/renesas-xhci";
static constexpr int POLARIS_RZG2L_USB3_PORT_COUNT = 1;
static constexpr int POLARIS_RZG2L_USB2_PORT_COUNT = 2;

// Ethernet.
static constexpr const char* POLARIS_RZG2L_ETH_IFACE      = "eth0";
static constexpr int         POLARIS_RZG2L_ETH_SPEED_MBPS = 1000;

// Camera/video (V4L2).
static constexpr const char* POLARIS_RZG2L_CSI_DEVICE0 = "/dev/video0";
static constexpr const char* POLARIS_RZG2L_CSI_DEVICE1 = "/dev/video1";
static constexpr const char* POLARIS_RZG2L_MEDIA_CTL0  = "/dev/media0";
static constexpr const char* POLARIS_RZG2L_UNICAM_PATH = "/sys/bus/platform/devices";

// Display nodes.
static constexpr const char* POLARIS_RZG2L_DRM_CARD0 = "/dev/dri/card0";
static constexpr const char* POLARIS_RZG2L_DRM_CARD1 = "/dev/dri/card1";

// Audio.
static constexpr const char* POLARIS_RZG2L_I2S_DEVICE = "/sys/bus/platform/devices";
static constexpr const char* POLARIS_RZG2L_ALSA_CARDS = "/proc/asound/cards";

// Serial (SCIF debug UART).
static constexpr const char* POLARIS_RZG2L_DEBUG_UART = "/dev/ttySC0";
static constexpr const char* POLARIS_RZG2L_UART1      = "/dev/ttySC1";

// Thermal thresholds.
static constexpr const char* POLARIS_RZG2L_THERMAL_CPU_ZONE   = "/sys/class/thermal/thermal_zone0";
static constexpr const char* POLARIS_RZG2L_THERMAL_SB_ZONE    = "/sys/class/thermal/thermal_zone1";
static constexpr double      POLARIS_RZG2L_THERMAL_THROTTLE_C = 95.0;
static constexpr double      POLARIS_RZG2L_THERMAL_SHUTDOWN_C = 110.0;

// GPIO via libgpiod.
static constexpr const char* POLARIS_RZG2L_GPIOCHIP_PATH = "/dev/gpiochip0";
static constexpr int         POLARIS_RZG2L_GPIO_PIN_COUNT = 96;

// Cortex-M33 remoteproc + RPMsg.
static constexpr int         POLARIS_RZG2L_PRU_REMOTEPROC_ID = 0;
static constexpr const char* POLARIS_RZG2L_PRU_REMOTEPROC_BASE = "/sys/class/remoteproc";
static constexpr const char* POLARIS_RZG2L_PRU_RPMSG_DEVICE = "/dev/rpmsg_m33";
static constexpr const char* POLARIS_RZG2L_PRU_FIRMWARE_DEFAULT = "rzg2l-m33-fw";

// Storage paths.
static constexpr const char* POLARIS_RZG2L_MMCBLK_PATH = "/dev/mmcblk0";
static constexpr const char* POLARIS_RZG2L_NVME_PATH   = "/dev/nvme0n1";

// PMIC/power supply.
static constexpr const char* POLARIS_RZG2L_POWER_SUPPLY_PATH = "/sys/class/power_supply";

// Optional external AI accelerators.
static constexpr const char* POLARIS_RZG2L_HAILO8_PCIE_VENDOR = "1e60";
static constexpr const char* POLARIS_RZG2L_CORAL_USB_VENDOR   = "18d1";

// Platform identification.
static constexpr const char* PLATFORM_NAME      = "Polaris RZ/G2L Platform";
static constexpr const char* PLATFORM_SOC       = "Renesas RZ/G2L";
static constexpr const char* PLATFORM_IOBRIDGE  = "Cortex-M33";
static constexpr const char* POLARIS_RZG2L_DT_MODEL_PATH = "/proc/device-tree/model";
