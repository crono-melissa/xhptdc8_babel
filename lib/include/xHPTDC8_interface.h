//
// Header file containing structs and #defines specific for the xHPTDC8
// The current driver version for xHPTDC8 devices is 0.0.18.0
// 
// 

/**
* The functions provided by the API are declared in xTDC8_interface.h. 
* The API is a DLL with C linkage.
*/
#ifndef XHPTDC8_INTERFACE_H
#define XHPTDC8_INTERFACE_H

#include "crono_interface.h"

/**
*	All ERRORS must be positive, because the upper byte is used by crono_tools
*/

#define XHPTDC8_API_VERSION 1
#define XHPTDC8_STATIC_INFO_VERSION 1
#define XHPTDC8_FAST_INFO_VERSION 2
#define XHPTDC8_PARAM_INFO_VERSION 2
#define XHPTDC8_TEMP_INFO_VERSION 3
#define XHPTDC8_CLOCK_INFO_VERSION 1
#define XHPTDC8_DEVICE_CONFIG_VERSION 3
#define XHPTDC8_MANAGER_CONFIG_VERSION 1

// The maximum number of boards supported by the device manager.
#define	XHPTDC8_MANAGER_DEVICES_MAX 8
// The number of TDC input channels.
#define XHPTDC8_TDC_CHANNEL_COUNT 8
// The number of gating blocks. One for each TDC input.
#define XHPTDC8_GATE_COUNT 8
// The number of timing generators. One for each TDC input and one for the adc trigger.
#define XHPTDC8_TIGER_COUNT 9
// The number of potential trigger sources for the timing generators. One for each TDC input plus some specials.
#define XHPTDC8_TRIGGER_COUNT 16		

#define XHPTDC8_BUFFER_ALLOCATE		0	
#define XHPTDC8_BUFFER_USE_PHYSICAL	1	

#define XHPTDC8_INPUT_BASELINE			+1.32
#define XHPTDC8_THRESHOLD_P_NIM			+0.35
#define XHPTDC8_THRESHOLD_P_CMOS		+1.18
#define XHPTDC8_THRESHOLD_P_LVCMOS_33	+1.18
#define XHPTDC8_THRESHOLD_P_LVCMOS_25	+1.18
#define XHPTDC8_THRESHOLD_P_LVCMOS_18	+0.90
#define XHPTDC8_THRESHOLD_P_TTL			+1.18
#define XHPTDC8_THRESHOLD_P_LVTTL_33	+1.18
#define XHPTDC8_THRESHOLD_P_LVTTL_25	+1.18
#define XHPTDC8_THRESHOLD_P_SSTL_3		+1.18
#define XHPTDC8_THRESHOLD_P_SSTL_2		+1.18
#define XHPTDC8_THRESHOLD_N_NIM			-0.35
#define XHPTDC8_THRESHOLD_N_CMOS		-1.32
#define XHPTDC8_THRESHOLD_N_LVCMOS_33	-1.32
#define XHPTDC8_THRESHOLD_N_LVCMOS_25	-1.25
#define XHPTDC8_THRESHOLD_N_LVCMOS_18	-0.90
#define XHPTDC8_THRESHOLD_N_TTL			-1.32
#define XHPTDC8_THRESHOLD_N_LVTTL_33	-1.32
#define XHPTDC8_THRESHOLD_N_LVTTL_25	-1.25
#define XHPTDC8_THRESHOLD_N_SSTL_3		-1.32
#define XHPTDC8_THRESHOLD_N_SSTL_2		-1.25

// All sources ignored
#define XHPTDC8_TRIGGER_SOURCE_NONE				0x00000000
#define XHPTDC8_TRIGGER_SOURCE_A				0x00000001	// 0
#define XHPTDC8_TRIGGER_SOURCE_B				0x00000002	// 1
#define XHPTDC8_TRIGGER_SOURCE_C				0x00000004	// 2
#define XHPTDC8_TRIGGER_SOURCE_D				0x00000008	// 3
#define XHPTDC8_TRIGGER_SOURCE_E				0x00000010	// 4
#define XHPTDC8_TRIGGER_SOURCE_F				0x00000020	// 5
#define XHPTDC8_TRIGGER_SOURCE_G				0x00000040	// 6
#define XHPTDC8_TRIGGER_SOURCE_H				0x00000080	// 7
#define XHPTDC8_TRIGGER_SOURCE_TDC1_SYNC		0x00000100	// 8
#define XHPTDC8_TRIGGER_SOURCE_TDC2_SYNC		0x00000200	// 9
#define XHPTDC8_TRIGGER_SOURCE_TDC_EXT_SYNC		0x00000400	// 10
#define XHPTDC8_TRIGGER_SOURCE_ADC1_CNV			0x00000800	// 11
#define XHPTDC8_TRIGGER_SOURCE_ADC2_CNV			0x00001000	// 12
#define XHPTDC8_TRIGGER_SOURCE_SOFTWARE			0x00002000	// 13
#define XHPTDC8_TRIGGER_SOURCE_AUTO				0x00004000	// 14
#define XHPTDC8_TRIGGER_SOURCE_ONE				0x00008000	// 15

#define XHPTDC8_TDCHIT_TYPE_RISING						  1
// Some error occured.
#define XHPTDC8_TDCHIT_TYPE_ERROR						  2
// At least one TDC timestamp missing due to full buffers (second level Fifo).
#define XHPTDC8_TDCHIT_TYPE_ERROR_TIMESTAMP_LOST		  4	
// Internal rollover flag lost, timestamps invalid.
#define XHPTDC8_TDCHIT_TYPE_ERROR_ROLLOVER_LOST			  8	
// At least one TDC timestamp missing due to full buffers (DMA pipeline stalled).
#define XHPTDC8_TDCHIT_TYPE_ERROR_PACKETS_LOST			 16	
// At least one TDC timestamp missing due to full buffers (DMA pipeline stalled)
#define XHPTDC8_TDCHIT_TYPE_ERROR_SHORTENED				 32		
// At least one TDC timestamp missing due to full buffers (DMA Fifo full).
#define XHPTDC8_TDCHIT_TYPE_ERROR_DMA_FIFO_FULL			 64		
// At least one TDC timestamp missing due to full buffers (ring buffer full).
#define XHPTDC8_TDCHIT_TYPE_ERROR_HOST_BUFFER_FULL		128 	
// ADC data recorded by internal trigger.
#define XHPTDC8_TDCHIT_TYPE_ADC_INTERNAL				  1 	
// Some error occured.
#define XHPTDC8_TDCHIT_TYPE_ADC_ERROR					  2		
// Unused error flag.
#define XHPTDC8_TDCHIT_TYPE_ADC_ERROR_UNUSED			  4	
// ADC trigger pulse violated timing requirements, data may be invalid,
#define XHPTDC8_TDCHIT_TYPE_ADC_ERROR_INVALID_TRIGGER	  8	
// At least one ADC sample missing due to full buffers.
#define XHPTDC8_TDCHIT_TYPE_ADC_ERROR_DATA_LOST			 16		

// Error codes

#define XHPTDC8_OK							CRONO_OK
#define XHPTDC8_WINDRIVER_NOT_FOUND			CRONO_WINDRIVER_NOT_FOUND
#define XHPTDC8_DEVICE_NOT_FOUND			CRONO_DEVICE_NOT_FOUND
#define XHPTDC8_NOT_INITIALIZED				CRONO_NOT_INITIALIZED
#define XHPTDC8_WRONG_STATE					CRONO_WRONG_STATE
#define XHPTDC8_INVALID_DEVICE				CRONO_INVALID_DEVICE
#define XHPTDC8_BUFFER_ALLOC_FAILED			CRONO_BUFFER_ALLOC_FAILED
#define XHPTDC8_TDC_NO_EDGE_FOUND			CRONO_TDC_NO_EDGE_FOUND
#define XHPTDC8_INVALID_BUFFER_PARAMETERS	CRONO_INVALID_BUFFER_PARAMETERS
#define XHPTDC8_INVALID_CONFIG_PARAMETERS	CRONO_INVALID_CONFIG_PARAMETERS
#define XHPTDC8_TDC_ALIGNMENT_FAILED		CRONO_WINDOW_CALIBRATION_FAILED
#define XHPTDC8_HARDWARE_FAILURE			CRONO_HARDWARE_FAILURE
#define XHPTDC8_INVALID_ADC_MODE			CRONO_INVALID_ADC_MODE
#define XHPTDC8_SYNCHRONIZATION_FAILED		CRONO_SYNCHRONIZATION_FAILED
#define XHPTDC8_DEVICE_OPEN_FAILED			CRONO_DEVICE_OPEN_FAILED
#define XHPTDC8_INTERNAL_ERROR				CRONO_INTERNAL_ERROR
#define XHPTDC8_CALIBRATION_FAILURE			CRONO_CALIBRATION_FAILURE
#define XHPTDC8_INVALID_ARGUMENTS			CRONO_INVALID_ARGUMENTS

// Device states

#define XHPTDC8_DEVICE_STATE_CREATED		CRONO_DEVICE_STATE_CREATED
#define XHPTDC8_DEVICE_STATE_INITIALIZED	CRONO_DEVICE_STATE_INITIALIZED
#define XHPTDC8_DEVICE_STATE_CONFIGURED		CRONO_DEVICE_STATE_CONFIGURED
#define XHPTDC8_DEVICE_STATE_CAPTURING		CRONO_DEVICE_STATE_CAPTURING
#define XHPTDC8_DEVICE_STATE_PAUSED			CRONO_DEVICE_STATE_PAUSED
#define XHPTDC8_DEVICE_STATE_CLOSED			CRONO_DEVICE_STATE_CLOSED


#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_WIN64)
#ifdef XHPTDC8_DRIVER_EXPORTS
#define XHPTDC8_API __declspec(dllexport)
#else
#define XHPTDC8_API __declspec(dllimport)
#endif
#else
#define __int64 long long
#define XHPTDC8_API 
#endif

#define crono_bool_t unsigned char

	// Handle to manager information struct
	typedef void* xhptdc8_manager;

	/**
	struct for the initialization of the xTDC8Manager. 
	This structure MUST be completely INITIALIZED. 
	*/
	typedef struct {
		/*
		That is increased when the definition of the structure is changed.

		Set to 0 for all versions up to first release.
		Must be set to XHPTDC8_API_VERSION.
		*/
		int version; 

		/* 
		The minimum size of the DMA buffer. 
		If set to 0, the default size of 16MB is used.
		For the xHPTDC8 only the first entry is used.
		*/
		__int64 buffer_size;

		/* 
		A variant, for reconfiguring the chip for future extension. 
		*/
		int variant;

		/*
		A constant for the different devices of cronologic CRONO_DEVICE_*.
		Initialized by initialization xhptdc8_get_default_init_parameters(). 
		Must be left unchanged. 
		*/
		int device_type;

		/*
		The update delay of the writing pointer after a packet has been send over PCIe. Specified in
		multiples of 16 ns. Should not be changed by the user. 
		The base unit is 16 to 32 ns.
		*/
		int dma_read_delay;

		/*
		Several xHPTDC8 are used in sync.
		If set to 1 enable multiboard operation. If set to 0 disable multiboard operation.
		Value is either 'true' or 'false'. 
		*/
		crono_bool_t multiboard;

		/*
		Select external 10 MHz reference.
		If set to 1 use external 10 MHz reference. If set to 0 use internal reference.
		Value is either 'true' or 'false'.
		*/
		crono_bool_t use_ext_clock;

		/*
		Value is either 'true' or 'false'.
		*/
		crono_bool_t ignore_calibration;

	} xhptdc8_manager_init_parameters;

	/** 
	struct for the initialization of the xTDC8Manager. 
	This structure MUST be completely INITIALIZED. 
	*/
	typedef struct {
		/*
		The time stamp of the hit in picoseconds.
		If grouping is enabled the timestamp is relative to the trigger or the separate 
		zero reference of the group.Otherwise the timestampe is continuously
		counting up from the call to start_capture()
		*/
		long long time;

		/*
		For the forst in the system this 0 to 7 for the TDC channels A to H. 8 or 9 for ADC data.
		Data from channels 8 and 9 should usually be treated as data from the same channel. 
		For the other boards the channel number is incremented by board_id. 10
		*/
		unsigned char channel;

		/*
		Additional information on the type of hit recorded.
		It is of one of the values XHPTDC8_TDCHIT_TYPE_*
		*/
		unsigned char type;

		/*
		For ADC hits this contains the sampled voltage. For TDC hits the content is undefined.
		*/
		unsigned short bin;

	} TDCHit;

	/** 
	* Read a multitude of hits into a buffer provided by the user.
	* If grouping is enabled a single group is read.
	* If grouping is disabled all availabe data is read.
	* In all cases, data is copied to buffer up to the size of the buffer.
	* 
	* @param hMgr[in]. It must be initialized using xhptdc8_init().
	* @param hit_buf[out]. Buffer allocated and provdied by the user.
	* @param read_max[out]. Size of the buffer.
	*
	* @returns Returns the number of read hits.
	*/
	XHPTDC8_API int xhptdc8_read_hits(xhptdc8_manager hMgr, TDCHit* hit_buf, size_t read_max);

	/**
	* Finalize the driver for this device.
	* 
	* @param hMgr[in]. It must be initialized using xhptdc8_init().
	*
	* @returns XHPTDC8_OK in case of success, or error code in case of error.
	*/
	XHPTDC8_API int xhptdc8_close(xhptdc8_manager hMgr);

	/**
	* Start the timing generator of an individual board. 
	* This can be done independently of the state of the data acquisition
	* 
	* @param hMgr[in]. It must be initialized using xhptdc8_init().
	* @param index[in]. The index of the device.
	*
	* @returns XHPTDC8_OK in case of success, or error code in case of error.
	*/
	XHPTDC8_API int xhptdc8_start_tiger(xhptdc8_manager hMgr, int index);

	/**
	* Stop the timing generator of an individual board. 
	* This can be done independently of the state of the data acquisition
	*
	* @param hMgr[in]. It must be initialized using xhptdc8_init().
	* @param index[in]. The index of the device.
	*
	* @returns XHPTDC8_OK in case of success, or error code in case of error.
	*/
	XHPTDC8_API int xhptdc8_stop_tiger(xhptdc8_manager hMgr, int index);

	/**
	* Start data acquisition. 
	* 
	* @param hMgr[in]. It must be initialized using xhptdc8_init().
	* 
	* @returns XHPTDC8_OK in case of success, or error code in case of error.
	*/
	XHPTDC8_API int xhptdc8_start_capture(xhptdc8_manager hMgr);

	/**
	* Pause a started data acquisition. 
	* It doesn�t allow for a configuration change.
	*
	* @param hMgr[in]. It must be initialized using xhptdc8_init().
	*
	* @returns XHPTDC8_OK in case of success, or error code in case of error.
	*/
	XHPTDC8_API int xhptdc8_pause_capture(xhptdc8_manager hMgr);

	/**
	* Call this to resume data acquisition after a call to xhptdc8_pause_capture(). 
	* It doesn�t allow for a configuration change.
	*
	* @param hMgr[in]. It must be initialized using xhptdc8_init().
	*
	* @returns XHPTDC8_OK in case of success, or error code in case of error.
	*/
	XHPTDC8_API int xhptdc8_continue_capture(xhptdc8_manager hMgr);

	/**
	* Stop data acquisition. 
	*
	* @param hMgr[in]. It must be initialized using xhptdc8_init().
	*
	* @returns XHPTDC8_OK in case of success, or error code in case of error.
	*/
	XHPTDC8_API int xhptdc8_stop_capture(xhptdc8_manager hMgr);

	/**
	Structure contains static information.

	This structure contains information about the board that does not change during run time.
	It is provided by the function xhptdc8_get_static_info().
	*/
	typedef struct {
		/**
		The number of bytes occupied by the structure.
		*/
		int size; 

		/**	
		A version number that is increased when the definition of the structure is changed.

		The increment can be larger than one to match driver version numbers or similar.
		Currently only version 0 is defined.
		*/
		int version; 

		/**
		ID of the board.
		All xHPTDC8 boards in the system are numbered according in order of their serial numbers starting at zero.
		*/
		int board_id;

		/**	
		Encoded version number for the driver.

		The lower three bytes contain a triple level hierarchy of version numbers.
		E.g. 0x010103 codes version 1.1.3.
		
		A change in the first digit generally requires a recompilation of user applications. 
		Change in the second digit denote significant improvements or changes that don't break compatibility 
		and the third digit changes with minor bugfixes and the like.
		*/
		int driver_revision;

		/**
		The build number of the driver according to cronologic�s internal versioning system.
		*/
		int driver_build_revision;

		/**
		Revision number of the FPGA configuration
		*/
		int firmware_revision; 

		/**
		Board revision number.

		The board revision number can be read from a register. It is a four bit number
		that changes when the schematic of the board is changed.
		- 0: Experimental first board Version. Labeled "Rev. 1"
		- 2: First commercial Version. Labeled "Rev. 2"
		*/
		int board_revision;

		/** 
		Describes the schematic configuration of the board.
		
		The same board schematic can be populated in multiple variants. 
		This is a four bit-code that can be read from a register.
		*/
		int board_configuration;

		/**
		Subversion revision id of the FPGA configuration.
		
		A number to track builds of the firmware in more detail than the firmware revision. It changes
		with every change in the firmware, even if there is no visible effect for the user. The subversion
		revision number can be read from a register.
		*/
		int subversion_revision;

		/**
		16bit factory ID of the TDC chip.

		This is the chipID as read from the 16 bit TDC chip id register at SPI address 0x83.
		This value should be cached.
		*/
		int chip_id[2]; 

		/*
		Serial number
		
		With year and running number in 8.24 format. The number is identical to the one
		printed on the silvery sticker on the board.
		*/
		int board_serial;

		/**
		High 32 bits of 64 bit manufacturer serial number of the flash chip.
		*/
		unsigned int flash_serial_high;

		/**
		Low 32 bits of 64 bit manufacturer serial number of the flash chip.
		*/
		unsigned int flash_serial_low;	

		/**
		Flash data is valid and in use.
		
		If not 'false', the driver found valid calibration data in the flash on the board and is using it.
		*/
		crono_bool_t flash_valid;

		/**
		Calibration date
		
		DIN EN ISO 8601 string YYYY-MM-DD HH:DD describing the time when the card was calibrated.
		*/
		char calibration_date[20];
	} xhptdc8_static_info;

	/**
	* Contains static information
	*
	* Gets a structure that contains information about the board that does not change during 
	* run time.
	* 
	* @param hMgr[in]. It must be initialized using xhptdc8_init().
	* @param index[in].The index of the device.
	* @param info[out]. Buffer allocated and provdied by the user to have a copy of the structure.
	*
	* @returns XHPTDC8_OK in case of success, or error code in case of error.
	*/
	XHPTDC8_API int xhptdc8_get_static_info(xhptdc8_manager hMgr, int index, xhptdc8_static_info* info);

	/**
	Contains fast dynamic information.

	This structure is filled using function xhptdc8_get_fast_info().
	*/
	typedef struct {
		/**
		The number of bytes occupied by the structure
		*/
		int size;

		/**	
		A version number that is increased when the definition of the structure is changed.

		The increment can be larger than one to match driver version numbers or similar.
		Currently only version 0 is defined.
		*/
		int version; 

		/**
		Speed of the FPGA fan in rounds per minute.

		Reports 0, if no fan is present.
		*/
		int fpga_rpm;

		/**
		Alert bits from temperature sensor and the system monitor. 
		
		Bit 0 is set if the TDC temperature exceeds 140�C. In this case the TDC did shut down 
		and the device needs to be reinitialized.
		*/
		int alerts;
		
		/*
		Organizes power supply of PCIe lanes. 
		Is always 0.
		*/
		int pcie_pwr_mgmt;

		/**
		Number of PCIe lanes the card uses.
		Should always be 1 for the xHPTDC8.
		*/
		int pcie_link_width;

		/**
		Maximum size for a single PCIe transaction in bytes. Depends on system configuration.
		*/
		int pcie_max_payload;

		/**
		The state the XHPTDC8Manager is in.
		It is of one of the values XHPTDC8_DEVICE_STATE_*
		*/
		int state;
	} xhptdc8_fast_info;

	/**
	* Returns fast dynamic information
	*
	* This call gets a structure that contains dynamic information that can be obtained within a
	* few microseconds.
	* 
	* @param hMgr[in]. It must be initialized using xhptdc8_init().
	* @param info[out]. Buffer allocated and provdied by the user to have a copy of the structure.
	*
	* @returns XHPTDC8_OK in case of success, or error code in case of error.
	*/
	XHPTDC8_API int xhptdc8_get_fast_info(xhptdc8_manager hMgr, int index, xhptdc8_fast_info * info);

	/** 
	Contains configuration changes

	Structure is filled byxhptdc8_get_param_info(). 
	This structure contains information that change indirectly due to configuration changes.
	*/
	typedef struct {
		/**
		The number of bytes occupied by the structure.
		*/
		int size;

		/*
		A version number that is increased when the definition of the structure is changed.

		The increment can be larger than one to match driver version numbers or similar.
		Currently only version 0 is defined.
		*/
		int version; 

		/*
		Binsize (in ps) of the measured TDC data.

		The TDC main clk is running at a frequency of 76.8 GHz resulting in a binsize of ~13.0208 ps.
		*/
		double binsize;

		/**
		Number of TDC channels of the board.

		It's currently fixed at 8.
		*/
		int channels;

		/*
		Bit assignment of each enabled input channel.

		Bit 0 <= n < 8 is set if channel n is enabled.
		*/
		int channel_mask;

		/**
		The total amount of DMA buffer in bytes.
		*/
		__int64 total_buffer;
	} xhptdc8_param_info;

	/**
	* Returns configuration changes
	*
	* Gets a structure that contains information that changes indirectly due to configuration
	* changes. 
	* 
	* @param hMgr[in]. It must be initialized using xhptdc8_init().
	* @param info[out]. Buffer allocated and provdied by the user to have a copy of the structure.
	* 
	* @returns XHPTDC8_OK in case of success, or error code in case of error.
	*/
	XHPTDC8_API int xhptdc8_get_param_info(xhptdc8_manager hMgr, int index, xhptdc8_param_info* info);

	/**
	Contains temperature measurements

	CAVE: TDC temp diode takes about 2.5 us after wakeup from power down to provide a valid measurement
	Structure filled by xhptdc8_get_temperature_info() 
	*/
	typedef struct {
		/**
		The number of bytes occupied by the structure
		*/
		int size;

		/**
		A version number that is increased when the definition of the structure is changed.

		The increment can be larger than one to match driver version numbers or similar.
		Currently only version 0 is defined.
		*/
		int version;

		/**
		Temperature for each of the TDC chips in �C.
		*/
		float tdc[2];

		/**
		Temperature in �C read from the FPGA�s internal sensor.
		*/
		int fpga;
	} xhptdc8_temperature_info;

	/**
	* Get temperature measurements from multiple sources on the board.
	* 
	* @param hMgr[in]. It must be initialized using xhptdc8_init().
	* @param index[in]. The index of the device.
	* @param info[out]. Buffer allocated and provdied by the user to have a copy of the structure.
	*
	* @returns XHPTDC8_OK in case of success, or error code in case of error.
	*/
	XHPTDC8_API int xhptdc8_get_temperature_info(xhptdc8_manager hMgr, int index, xhptdc8_temperature_info* info);

// External 10 MHz provided at J12 (no longer supported)
#define XHPTDC8_CLK_J12 1
// Internal 10 MHz oscillator
#define XHPTDC8_CLK_OSC 2
// External 10 MHz provided at the internal LEMO connector 
#define XHPTDC8_CLK_LEMO 4

	/**
	Contains temperature measurements

	Structure is filled by xhptdc8_get_temperature_info().
	*/
	typedef struct {
		/**
		The number of bytes occupied by the structure.
		*/
		int size;

		/**
		A version number that is increased when the definition of the structure is changed.

		The increment can be larger than one to match driver version numbers or similar.
		Currently only version 0 is defined.
		*/
		int version;

		/**
		CDCE62005 PLL locked. Set if the jitter cleaning PLL clock synthesizer achieved lock.
		Value is either 'true' or 'false'.
		*/
		crono_bool_t cdce_locked;

		/**
		Version information from the CDCE62005 clock synthesizer.
		*/
		int cdce_version;

		/**
		Source for the clock synthesizer is usually the 10MHz on board oscillator.
		Value: 'false': internal 10 MHz, 'true': LEMO clock
		*/
		crono_bool_t use_ext_clock; 

		/**
		Set if the FPGA datapath PLL achieved lock.
		Value is either 'true' or 'false'.
		*/
		crono_bool_t fpga_locked;
	} xhptdc8_clock_info;

	/**
	* Get information on clocking configuration an status.
	* 
	* @param hMgr[in]. It must be initialized using xhptdc8_init().
	* @param index[in]. The index of the device.
	* @param info[out]. Buffer allocated and provdied by the user to have a copy of the structure.
	*
	* @returns XHPTDC8_OK in case of success, or error code in case of error.
	*/
	XHPTDC8_API int xhptdc8_get_clock_info(xhptdc8_manager hMgr, int index, xhptdc8_clock_info* info);

	/**
	* Returns most recent error message.
	* 
	* @param hMgr[in]. It must be initialized using xhptdc8_init().
	* @param index[in]. The index of the device.
	*/
	XHPTDC8_API const char* xhptdc8_get_last_error_message(xhptdc8_manager hMgr, int index = -1);
	
	/**
	* Returns the type of the device as CRONO_DEVICE_XHPTDC8.
	*
	* @param hMgr[in]. It must be initialized using xhptdc8_init().
	* @param index[in]. The index of the device.
	*/
	XHPTDC8_API int xhptdc8_get_device_type(xhptdc8_manager hMgr, int index);

	/**
	Contains TDC channel settings.
	*/
	typedef struct {
		/**
		Enable TDC channel.
		Value is either 'true' or 'false'.
		*/
		crono_bool_t enable; 

		/**
		Select which edge of the signal is measured by the TDC.
		Value is either 'true' or 'false'.
		*/
		crono_bool_t rising;
	} xhptdc8_channel;

// Gate deactivated
#define XHPTDC8_GATE_OFF 0 
// Gate activated
#define XHPTDC8_GATE_ON 1
// TiGeR deactivated
#define XHPTDC8_TIGER_OFF 0
// Pulse height approx. 2 V. LEMO only usable as output 
#define XHPTDC8_TIGER_OUTPUT 1
// Pulse height approx. 1 V. LEMO may be used as input with OR function when external pulse rate is low. 
#define XHPTDC8_TIGER_BIDI 2
// Bipolar pulse
#define XHPTDC8_TIGER_BIPOLAR 3
// Maximum length of bipolar TiGeR pulses
#define XHPTDC8_TIGER_MAX_BIPOLAR_PULSE_LENGTH 15
	
	/*
	Contains settings of timing generator.
	*/
	typedef struct {
		/**
		Enables the desired mode of operation for the tiger.
		It is of one of the values XHPTDC8_TIGER_*
		*/
		int mode;

		/**
		Inverts output polarity. 
		For gating blocks, a value of 'false' blocks inputs between start and stop, 
		a value of 'true' blocks outputs outside that interval. 
		The TiGer creates a high pulse from start to stop unless negated.
		Default value is 'false'.
		*/
		crono_bool_t negate;

		/**
		Enables retrigger setting.
		If enabled, the timer is reset to the value of the start parameter, 
		whenever the input signal is set while waiting to reach the stop time.
		Value is either 'true' or 'false'.
		Default value is 'false'
		*/
		crono_bool_t retrigger;
		
		/**
		Not implemented.
		*/
		crono_bool_t extend;

		/** 
		The start time at which the TiGer output is set, relative to the trigger input.
		It is in multiples of 20 ns/3 = 6.6 ns.
		Must fullfil condition: 0 <= start <= stop <= (2^16 - 1)
		*/
		int start;

		/**
		The start time at which which the TiGer output is set, relative to the trigger input.
		It is in multiples of 20 ns/3 = 6.6 ns.
		Must fullfil condition: 0 <= start <= stop <= (2^16 - 1)
		*/

		/**
		The duration from start time in which the TiGer output is set, relative to the trigger input.
		It is in multiples of 20 ns/3 = 6.6 ns.
		Must fullfil condition: 0 <= start <= stop <= (2^16 - 1)
		*/
		int stop;

		/**
		A bit mask with a bit set for all trigger sources that can trigger this TiGer block. 
		Default value is XHPTDC8_TRIGGER_SOURCE_A.
		*/
		int sources;
	} xhptdc8_tiger_block;

	/**
	For each input, this structure determines wheter rising or falling edges on the inputs create trigger
	events for the TiGer and gating blocks.
	*/
	typedef struct {
		/**
		If set to 'true', a trigger event is created inside the FPGA at the falling edge.
		Value is either 'true' or 'false'.
		*/
		crono_bool_t falling;
		/**
		If set to 'true', a trigger event is created inside the FPGA at the rising edge.
		Value is either 'true' or 'false'.
		*/
		crono_bool_t rising;
	} xhptdc8_trigger;

	/**
	ADC channel config 
	Contains ADC channel settings
	*/
	typedef struct {
		/**
		Enable ADC measurements.
		Value is either 'true' or 'false'.
		*/
		crono_bool_t enable;
		
		/**
		Send watchdog measurements.
		Value is either 'true' or 'false'.
		*/
		crono_bool_t watchdog_readout;

		/**
		Number of 150 MHz clock cycles between watchdog triggers.
		*/
		int watchdog_interval;

		/**
		Trigger threshold of ADC sample trigger.
		*/
		double trigger_threshold;
	} xhptdc8_adc_channel;

// Use TiGeR pulse for alignment (pulses are present on LEMO inputs during alignment).
#define XHPTDC8_ALIGN_TIGER 0
// Use internal alignment pins for alignment (no pulses are present on LEMO inputs during alignment).
#define XHPTDC8_ALIGN_PIN 1
// Use internal alignment pins for alignment and do not disable after alignment (internal use only).
#define XHPTDC8_ALIGN_RESERVED 2

#define XHPTDC8_GROUPING_VETO_OFF 0
#define XHPTDC8_GROUPING_VETO_INSIDE 1
#define XHPTDC8_GROUPING_VETO_OUTSIDE 2

	/**
	This structure configures the behaviour of the grouping functionality. 
	Grouping is enabled with the tdc_mode paramter defined in the top level of the config structure.
	*/
	typedef struct {
		/*
		Enable grouping. 
		Value is either 'true' or 'false'.
		Default value is 'false'.
		*/
		crono_bool_t enabled;

		/**
		Channel number that is used to trigger the creation of a group.
		*/
		int trigger_channel;

		/**
		Optionally, a different channel can be used to calculate the relative timestamps in a group. 
		This is disabled per default by setting this paramteer to -`.
		*/
		int zero_channel;

		/** 
		This offset in picoseconds is added to relative timestamps within a group.
		*/
		__int64 zero_channel_offset;

		/**
		Intervals are always provided in picoseconds, independently of the bin size of the TDC.
		*/
		__int64 range_start;

		/**
		Values in the interval from range_start to range_stop are included in the group. 
		Either or both values can be negative to create common-stop behaviour.
		-2^63 <= range_start <= range_stop < 2^63
		Intervals are always provided in picoseconds, independently of the bin size of the TDC.
		*/
		__int64 range_stop;

		/**
		Values in the interval from range_start to range_stop are included in the group.
		Either or both values can be negative to create common-stop behaviour.
		-2^63 <= range_start <= range_stop < 2^63
		Intervals are always provided in picoseconds, independently of the bin size of the TDC.
		*/
		__int64 trigger_deadtime;

		/*
		If set to 'true', a group is only created if there is at least one hit in the window  
		defined by window_start and window_stop.
		Value is either 'true' or 'false'.
		*/
		crono_bool_t require_window_hit;

		/**
		A group is only created if there is at least one hit in the window  defined by 
		window_start and window_stop, and when require_window_hit 'true'.
		-2^63 <= window_start <= window_stop < 2^63
		Intervals are always provided in picoseconds, independently of the bin size of the TDC.
		*/
		__int64 window_start;

		/**
		A group is only created if there is at least one hit in the window  defined by
		window_start and window_stop, and when require_window_hit 'true'.
		-2^63 <= window_start <= window_stop < 2^63
		Intervals are always provided in picoseconds, independently of the bin size of the TDC.
		*/
		__int64 window_stop;

		/**
		A window defined by veto_start and veto_stop can be used to suppress hits. 
		The functionality is very similar to the gating blocks but is defined in software.
		This feature can not be used to improve FIFO usage or PCIe bandwidth usage.
		It is of one of the values XHPTDC8_GROUPING_VETO_*
		*/
		int veto_mode;

		/**
		A window defined by veto_start and veto_stop can be used to suppress hits.
		-2^63 <= veto_start <= veto_stop < 2^63
		*/
		__int64 veto_start;

		/**
		A window defined by veto_start and veto_stop can be used to suppress hits.
		-2^63 <= veto_start <= veto_stop < 2^63
		*/
		__int64 veto_stop; 

		/*
		If set, the veto window is defined relative to the zero channel. 
		Otherwise the window is defined relative to the trigger.
		Value is either 'true' or 'false'.
		*/
		crono_bool_t veto_relative_to_zero;

		/*
		Unsupported, must remain 'false'.
		*/
		crono_bool_t overlap; 

	} xhptdc8_grouping_configuration;


	/** 
	This is the structure containing the configuration information. 
	It uses the multiple substructures to configure various aspects of the board.
	*/
	typedef struct {
		/**
		The number of bytes occupied by the structure.
		*/
		int size;

		/**
		A version number that is increased when the definition of the structure is changed.

		The increment can be larger than one to match driver version numbers or similar.
		Currently only version 0 is defined.
		*/
		int version;

		/**
		Create a trigger periodically.

		There are two parameters: M = auto_trigger_period
		and N = auto_trigger_random_exponent that result in a distance between triggers of T clock cycles.
		T = 1 + M + [1...2^N] clock cycles.
		0 <= M < 2^32
		0 <= N < 32
		There is no enable or reset. The auto trigger is running continously. 
		The usage of this trigger can be configured in the channels.
		*/
		int auto_trigger_period;
		/**
		Create a trigger randomly.

		There are two parameters: M = auto_trigger_period
		and N = auto_trigger_random_exponent that result in a distance between triggers of T clock cycles.
		T = 1 + M + [1...2^N] clock cycles.
		0 <= M < 2^32
		0 <= N < 32
		There is no enable or reset. The auto trigger is running continously.
		The usage of this trigger can be configured in the channels.
		*/
		int auto_trigger_random_exponent;

		/**
		Set the threshold voltage for the input channels A . . .H and TRG.
		threshold[0 - 7] : threshold for channels A...H.
		threshold[8] : threshold for channel TRG.
		Supported range is -1.32V to +1.18V. This should be close to 50% of the height of the input pulse.
		The inputs are AC coupled.
		Examples for various signaling standards are defined as XHPTDC8_INPUT_BASELINE and XHPTDC8_THRESHOLD_P*.
		*/
		double trigger_threshold[XHPTDC8_TDC_CHANNEL_COUNT];

		/**
		configuration the polarity of the external trigger sources.
		*/
		xhptdc8_trigger trigger[XHPTDC8_TRIGGER_COUNT];

		/**
		configuration of the gating blocks.
		*/
		xhptdc8_tiger_block gating_block[XHPTDC8_GATE_COUNT];

		/**
		Configuration of the timing generator blocks.
		*/
		xhptdc8_tiger_block tiger_block[XHPTDC8_TIGER_COUNT];

		/**
		configuration the TDC channels.
		*/
		xhptdc8_channel channel[XHPTDC8_TDC_CHANNEL_COUNT];

		/**
		configuration ADC channel.
		*/
		xhptdc8_adc_channel adc_channel;

		/*
		Configure TDC alignemet
		If set to 'true', skip TDC calibration. If set to 'false', do TDC calibration (default).
		Value is either 'true' or 'false'.
		*/
		crono_bool_t skip_alignment;

		/**
		Define a signal source that is used for phase alignment. Should usually be left unchanged.
		If set to XHPTDC8_ALIGN_TIGER use TiGeR pulse for alignment (pulses are present on LEMO inputs during alignment).
		If set to XHPTDC8_ALIGN_PIN use internal alignment pins for alignment (no pulses are present on LEMO inputs during alignment).
		If set to XHPTDC8_ALIGN_RESERVED use internal alignment pins for alignment and do not disable after alignment (internal use only).
		*/
		int alignment_source;

	} xhptdc8_device_configuration;


	/**
	Contains global configuration information.
	*/
	typedef struct {
		/**
		The number of bytes occupied by the structure.
		*/
		int size;

		/**
		A version number that is increased when the definition of the structure is changed.

		The increment can be larger than one to match driver version numbers or similar.
		Currently only version 0 is defined.
		*/
		int version;

		/**
		A structure with the configuration for an individual xHPTDC8 board.
		Use the function xhptdc8_count_devices() to query how many entries contain valid information.
		*/
		xhptdc8_device_configuration device_configs[XHPTDC8_MANAGER_DEVICES_MAX];

		/**
		Structure with the parameters for grouping.
		*/
		xhptdc8_grouping_configuration grouping;

		/**
		Reserved for future use.
		*/
		void* bin_to_ps;

	} xhptdc8_manager_configuration;

	/**
	* Gets default manager configuration. Copies the default configuration to the specified config pointer. 
	* 
	* @param hMgr[in]. It must be initialized using xhptdc8_init().
	* @param mgr_config[out].
	* 
	* @returns XHPTDC8_OK in case of success, or error code in case of error.
	*/
	XHPTDC8_API int xhptdc8_get_default_configuration(xhptdc8_manager hMgr, xhptdc8_manager_configuration *mgr_config);
	
	/**
	* Gets current configuration. Copies the current configuration to the specified config pointer.
	*
	* @param hMgr[in]. It must be initialized using xhptdc8_init().
	* @param mgr_config[out].
	*
	* @returns XHPTDC8_OK in case of success, or error code in case of error.
	*/
	XHPTDC8_API int xhptdc8_get_current_configuration(xhptdc8_manager hMgr, xhptdc8_manager_configuration *mgr_config);

	/**
	* Configures the xHPTDC8 manager. The config information is copied, so can be changed afterwards.
	*
	* @param hMgr[in]. It must be initialized using xhptdc8_init().
	* @param mgr_config[out].
	*
	* @returns XHPTDC8_OK in case of success, or error code in case of error.
	*/
	XHPTDC8_API int xhptdc8_configure(xhptdc8_manager hMgr, xhptdc8_manager_configuration *mgr_config);

	/**
	* Returns the number of boards present in the system that are supported by this driver.
	* 
	* @param error_code[out]. In case of success, it is assigned the value {0}, otherwise,
	* it is assigned the relevant error code.
	* @param error_message[out]. In case of error, it is assigned the error message.
	* 
	* @returns The number of boards present in the system that are supported by this driver.
	*/
	XHPTDC8_API int xhptdc8_count_devices(int *error_code, const char** error_message);

	/**	Sets up the standard parameters. 
	*
	* Gets a set of default parameters for xhptdc8_init(). This must always be used to initialize 
	* the xtdc8manager_init_parameters structure.
	* 
	* @param init[in].  
	* 
	* @returns XHPTDC8_OK in case of success, or error code in case of error.
	*/
	XHPTDC8_API int xhptdc8_get_default_init_parameters(xhptdc8_manager_init_parameters *init);

	/***
	* Opens and initializes the xHPTDC8 board with the index given in init->card_index.
	* 
	* @param hMgr[in]. It must be initialized using xhptdc8_init().
	* @param init[in]. A structure of type xhptdc8_init_parameters that must be completely initialized.
	* @param error_code[out]. shall point to an integer where the driver can write the the error code. 
	* In case of success, it is assigned the value {0}, otherwise, it is assigned the relevant error code.
	* @param error_message[out]. must point to a pointer to char. The driver will allocate a buffer for zero terminated
	* error message and store the address of the buffer in the location provided by the user In case of error, 
	* it is assigned the error message.
	*/
	XHPTDC8_API void xhptdc8_init(xhptdc8_manager *p_hMgr, xhptdc8_manager_init_parameters *params, int *error_code, const char** error_message);

	/**
	* Returns the driver version, same format as xhptdc8_static_info.driver_revision. This function does
	* not require a xHPTDC8 board to be present.
	*/
	XHPTDC8_API int xhptdc8_get_driver_revision();

	/**
	* Returns the driver version including SVN build revision as a string.
	*/
	XHPTDC8_API const char* xhptdc8_get_driver_revision_str();

	/**
	* Returns the state, corresponding to state code 'state', in string format. 
	* 
	* @papram state[in] 
	*/
	XHPTDC8_API const char* xhptdc8_device_state_to_str(int state);

#ifdef __cplusplus
}
#endif

#endif
