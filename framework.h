#ifndef framework_h_included
#define framework_h_included

/* Configuration */
#define DSP_SAMPLE_RATE         8000
#define DSP_BLOCK_SIZE          32
#define DSP_INPUT_GAIN_MIC      10
#define DSP_INPUT_GAIN_LINEIN   0
#define DSP_OUTPUT_ATTENUATION  0

/* Constants */
#define DSP_FREQUENCY           (12288000*16/2)
#define DSP_D1                  0x00000001
#define DSP_D2                  0x00000002
#define DSP_SW1                 0x00000008
#define DSP_SW2                 0x00000004
#define DSP_SW3                 0x00000002
#define DSP_SW4                 0x00000001

/* Sample frame */
typedef struct {
    _Fract left;
    _Fract right;
} sample_t;

/* Functions */
void dsp_init(void);
void dsp_start(void);
void dsp_stop(void);
sample_t *dsp_get_audio_out(void);
sample_t *dsp_get_audio_linein2(void);
sample_t *dsp_get_audio_linein1(void);
sample_t *dsp_get_audio_mic12(void);
sample_t *dsp_get_audio_mic34(void);
unsigned int dsp_get_keys(void);
unsigned int dsp_get_cycles(void);
void dsp_set_timer_period(unsigned int value);
void dsp_set_leds(unsigned int value);

#endif
