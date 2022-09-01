#include <asf.h>

#include "gfx_mono_ug_2832hsweg04.h"
#include "gfx_mono_text.h"
#include "sysfont.h"

#define LED_PIO      PIOA
#define LED_PIO_ID   ID_PIOA
#define LED_IDX      0
#define LED_IDX_MASK (1 << LED_IDX)

#define BUZZER_PIO PIOC
#define BUZZER_PIO_ID ID_PIOC
#define BUZZER_PIO_IDX 13
#define BUZZER_PIO_IDX_MASK (1 << BUZZER_PIO_IDX)

#define START_PIO	PIOD
#define START_PIO_ID	ID_PIOD
#define START_PIO_IDX	28
#define START_PIO_IDX_MASK (1u << START_PIO_IDX)

#define SELECAO_PIO	PIOC
#define SELECAO_PIO_ID		ID_PIOC
#define SELECAO_PIO_IDX	31
#define SELECAO_PIO_IDX_MASK (1u << SELECAO_PIO_IDX)

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0


int melody_zelda[] = {

	NOTE_E4,2, NOTE_G4,4,
	NOTE_D4,2, NOTE_C4,8, NOTE_D4,8,
	NOTE_E4,2, NOTE_G4,4,
	NOTE_D4,-2,
	NOTE_E4,2, NOTE_G4,4,
	NOTE_D5,2, NOTE_C5,4,
	NOTE_G4,2, NOTE_F4,8, NOTE_E4,8,
	NOTE_D4,-2,
	NOTE_E4,2, NOTE_G4,4,
	NOTE_D4,2, NOTE_C4,8, NOTE_D4,8,
	NOTE_E4,2, NOTE_G4,4,
	NOTE_D4,-2,
	NOTE_E4,2, NOTE_G4,4,

	NOTE_D5,2, NOTE_C5,4,
	NOTE_G4,2, NOTE_F4,8, NOTE_E4,8,
	NOTE_F4,8, NOTE_E4,8, NOTE_C4,2,
	NOTE_F4,2, NOTE_E4,8, NOTE_D4,8,
	NOTE_E4,8, NOTE_D4,8, NOTE_A3,2,
	NOTE_G4,2, NOTE_F4,8, NOTE_E4,8,
	NOTE_F4,8, NOTE_E4,8, NOTE_C4,4, NOTE_F4,4,
	NOTE_C5,-2,

};

int melody_pinkpanther[]={
	REST,2, REST,4, REST,8, NOTE_DS4,8,
	NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
	NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_E4,8, NOTE_G4,-8, NOTE_B4,8,
	NOTE_AS4,2, NOTE_A4,-16, NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16,
	NOTE_E4,2, REST,4, REST,8, NOTE_DS4,4,

	NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
	NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_G4,8, NOTE_B4,-8, NOTE_E5,8,
	NOTE_DS5,1,
	NOTE_D5,2, REST,4, REST,8, NOTE_DS4,8,
	NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
	NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_E4,8, NOTE_G4,-8, NOTE_B4,8,
	
	NOTE_AS4,2, NOTE_A4,-16, NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16,
	NOTE_E4,-4, REST,4,
	REST,4, NOTE_E5,-8, NOTE_D5,8, NOTE_B4,-8, NOTE_A4,8, NOTE_G4,-8, NOTE_E4,-8,
	NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8,
	NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16, NOTE_E4,16, NOTE_E4,16, NOTE_E4,2,
	};
	
int melody_imperialmarch[]={
	NOTE_A4,-4, NOTE_A4,-4, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_F4,8, REST,8,
	NOTE_A4,-4, NOTE_A4,-4, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_F4,8, REST,8,
	NOTE_A4,4, NOTE_A4,4, NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16,

	NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,//4
	NOTE_E5,4, NOTE_E5,4, NOTE_E5,4, NOTE_F5,-8, NOTE_C5,16,
	NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,
	
	NOTE_A5,4, NOTE_A4,-8, NOTE_A4,16, NOTE_A5,4, NOTE_GS5,-8, NOTE_G5,16, //7
	NOTE_DS5,16, NOTE_D5,16, NOTE_DS5,8, REST,8, NOTE_A4,8, NOTE_DS5,4, NOTE_D5,-8, NOTE_CS5,16,

	NOTE_C5,16, NOTE_B4,16, NOTE_C5,16, REST,8, NOTE_F4,8, NOTE_GS4,4, NOTE_F4,-8, NOTE_A4,-16,//9
	NOTE_C5,4, NOTE_A4,-8, NOTE_C5,16, NOTE_E5,2,

	NOTE_A5,4, NOTE_A4,-8, NOTE_A4,16, NOTE_A5,4, NOTE_GS5,-8, NOTE_G5,16, //7
	NOTE_DS5,16, NOTE_D5,16, NOTE_DS5,8, REST,8, NOTE_A4,8, NOTE_DS5,4, NOTE_D5,-8, NOTE_CS5,16,

	NOTE_C5,16, NOTE_B4,16, NOTE_C5,16, REST,8, NOTE_F4,8, NOTE_GS4,4, NOTE_F4,-8, NOTE_A4,-16,//9
	NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2
};

#define tempo 200


volatile char melody_flag;
int max_size=3;
int notes;
int wholenote = (60000 * 4) / tempo;
int divider = 0, noteDuration = 0;
volatile char start_flag;
volatile char change_flag;

void start_callback(void){
	start_flag=!start_flag;
}
void melody_callback(void){
	melody_flag+=1;
	if (melody_flag==max_size){
		melody_flag=0;
	}
	change_flag=1;
	
}

void set_buzzer() {
	pio_set(BUZZER_PIO, BUZZER_PIO_IDX_MASK);
	pio_clear(LED_PIO, LED_IDX_MASK);
}

void clear_buzzer() {
	pio_clear(BUZZER_PIO, BUZZER_PIO_IDX_MASK);
	pio_set(LED_PIO, LED_IDX_MASK);
}

int get_startstop() {
	return pio_get(START_PIO, PIO_INPUT, START_PIO_IDX_MASK);
}

int get_selecao() {
	return pio_get(SELECAO_PIO, PIO_INPUT, SELECAO_PIO_IDX_MASK);
}

void buzzer_test(int freq) {
	int delay = 1e6/(2*freq);  
	set_buzzer();
	delay_us(delay);
	clear_buzzer();
	delay_us(delay);
}

void tone(int freq, int t_ms) {
	double delay = 1e6/(2*freq);
	int duracao = (1e6*(t_ms)/1000)/(2*delay);
	
	for (int i = 0; i< duracao; i++) {
		set_buzzer();
		delay_us(delay);
		clear_buzzer();
		delay_us(delay);
	}
}

void init(void) {
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	pmc_enable_periph_clk(BUZZER_PIO_ID);
	pio_set_output(BUZZER_PIO, BUZZER_PIO_IDX_MASK, 0, 0, 0);
	
	pmc_enable_periph_clk(LED_PIO_ID);
	pio_configure(LED_PIO, PIO_OUTPUT_1, LED_IDX_MASK, PIO_DEFAULT);
	
	pmc_enable_periph_clk(START_PIO_ID);
	pio_set_input(START_PIO, START_PIO_IDX_MASK, PIO_DEFAULT);
	pio_configure(START_PIO, PIO_INPUT, START_PIO_IDX_MASK, PIO_PULLUP | PIO_DEBOUNCE);
	pio_set_debounce_filter(START_PIO, START_PIO_IDX_MASK, 60);

		
	pio_handler_set(START_PIO,
					START_PIO_ID,
					START_PIO_IDX_MASK,
					PIO_IT_FALL_EDGE,
					start_callback);
	pio_enable_interrupt(START_PIO, START_PIO_IDX_MASK);
	pio_get_interrupt_status(START_PIO);
	NVIC_EnableIRQ(START_PIO_ID);
	NVIC_SetPriority(START_PIO_ID, 4);
	
	
	
	
	pmc_enable_periph_clk(SELECAO_PIO_ID);
	pio_set_input(SELECAO_PIO, SELECAO_PIO_IDX_MASK, PIO_DEFAULT);
	pio_configure(SELECAO_PIO, PIO_INPUT, SELECAO_PIO_IDX_MASK, PIO_PULLUP | PIO_DEBOUNCE);
	pio_set_debounce_filter(SELECAO_PIO, SELECAO_PIO_IDX_MASK, 60);
	
	pio_handler_set(SELECAO_PIO,
					SELECAO_PIO_ID,
					SELECAO_PIO_IDX_MASK,
					PIO_IT_FALL_EDGE,
					melody_callback);
	pio_enable_interrupt(SELECAO_PIO, SELECAO_PIO_IDX_MASK);
	pio_get_interrupt_status(SELECAO_PIO);
	NVIC_EnableIRQ(SELECAO_PIO_ID);
	NVIC_SetPriority(SELECAO_PIO_ID, 4);

}




// todo usar macro em c para calcular tamanho
int *all_melodies[] = {&melody_zelda, &melody_pinkpanther, &melody_imperialmarch};
int all_melodies_size[] = {
			sizeof(melody_zelda) / sizeof(melody_zelda[0]) / 2, 
			sizeof(melody_pinkpanther) / sizeof(melody_pinkpanther[0]) / 2,
			sizeof(melody_imperialmarch) / sizeof(melody_imperialmarch[0]) / 2
			};
			
char name1[]="Zelda";
char name2[]="Pink Panther";
char name3[]="Star Wars";
char *all_melodies_names[]={&name1, &name2, &name3};
		
int main (void)
{
	board_init();
	sysclk_init();
	init();
	delay_init();

  // Init OLED
	gfx_mono_ssd1306_init();
  
  // Escreve na tela um circulo e um texto

  /* Insert application code here, after the board has been initialized. */
	while(1) {
		int *melody = all_melodies[melody_flag];
		
		notes = all_melodies_size[melody_flag];
		
		char *name=all_melodies_names[melody_flag];
		
		gfx_mono_draw_filled_rect(0, 0, 150, 20, GFX_PIXEL_CLR);
		gfx_mono_draw_string(name, 0,0, &sysfont);

		for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
			divider = melody[thisNote + 1];
			if (divider > 0) {
				noteDuration = (wholenote) / divider;
				} 
			else if (divider < 0) {
				noteDuration = (wholenote) / abs(divider);
				noteDuration *= 1.5;
			}
			
			

			

			while (start_flag){}
			if (change_flag){
				change_flag=0;
				break;
			}
			tone(melody[thisNote], noteDuration * 0.9);
			delay_ms(noteDuration*0.1);
			

		}
	}
}
