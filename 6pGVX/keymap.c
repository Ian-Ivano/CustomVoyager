#include QMK_KEYBOARD_H
#include "version.h"
#include "features/achordion.h" //custom feature
#include "features/sentence_case.h" //custom feature
#include "features/custom_shift_keys.h"//custom feature
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE
#define MAGIC LT(2,KC_0)//for tap-hold Alternate Repeat Key
#define REPEAT LT(4,KC_1)//for tap-hold REPEAT key 19.07.2025
//aliases for left Home Row Keys
#define HOME_A LT(1,KC_A)
#define HOME_R MT(MOD_LALT, KC_R)
#define HOME_S MT(MOD_LGUI, KC_S)
#define HOME_T MT(MOD_LSFT, KC_T)
//aliases for right Home Row keys
#define HOME_M LT(4,KC_M)
#define HOME_N MT(MOD_RSFT, KC_N)
#define HOME_E MT(MOD_RGUI, KC_E)
#define HOME_I MT(MOD_RALT, KC_I)
#define HOME_O LT(1,KC_O)
#define HYPER_F ALL_T(KC_F)    
#define HYPER_U ALL_T(KC_U)    
void housekeeping_task_user(void) {
  achordion_task();
}

enum custom_keycodes {
  M_TN = ML_SAFE_RANGE,
  M_SION,
  M_THE_1,
  M_WHAT,
  M_THE_2,
  M_YOU,
  M_LOCK,
  M_NUM,
  MAGIC_2,
  MAGIC_3,
  M_O,
  M_U,
  RGB_SLD,
  HSV_0_255_255,
  HSV_74_255_255,
  HSV_169_255_255,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
};



enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_TRANSPARENT, KC_Q,           KC_W,           HYPER_F,    KC_P,           KC_B,                                           KC_J,           KC_L,           HYPER_U,    KC_Y,           KC_SCLN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, HOME_A,     HOME_R,HOME_S,HOME_T,KC_G,                                           HOME_M,     HOME_N,HOME_E,HOME_I,HOME_O,KC_TRANSPARENT,       
    KC_TRANSPARENT, MT(MOD_LCTL, KC_Z),KC_X,           KC_C,           KC_D,           KC_V,                                           KC_K,           LT(3,KC_H),     TD(DANCE_0),    KC_DOT,         MT(MOD_RCTL, KC_SLASH),KC_TRANSPARENT, 
                                                    KC_SPACE,       LT(2,KC_TAB),                                   REPEAT, MAGIC
  ),
  [1] = LAYOUT_voyager(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_NO,          KC_QUOTE,       KC_LABK,        KC_RABK,        KC_DQUO,        KC_DOT,                                         KC_AMPR,        KC_UNDS,        TD(DANCE_1),    ST_MACRO_0,     KC_PERC,        KC_F12,         
    QK_LLCK,        KC_TRANSPARENT, KC_MINUS,       KC_PLUS,        KC_EQUAL,       KC_HASH,                                        KC_PIPE,        KC_COLN,        TD(DANCE_2),    ST_MACRO_1,     KC_TRANSPARENT, QK_LLCK,        
    KC_NO,          KC_CIRC,        KC_SLASH,       KC_ASTR,        KC_BSLS,        KC_NO,                                          KC_TILD,        KC_DLR,         TD(DANCE_3),    ST_MACRO_2,     KC_AT,          KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_0
  ),
  [2] = LAYOUT_voyager(
    RGB_TOG,        TOGGLE_LAYER_COLOR,RGB_MODE_FORWARD,RGB_SLD,        RGB_VAD,        RGB_VAI,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  KC_TRANSPARENT,                                 KC_PAGE_UP,     KC_HOME,        KC_TRANSPARENT,          KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,QK_LLCK,                                        KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_UP,       KC_RIGHT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, HSV_0_255_255,  HSV_74_255_255, HSV_169_255_255,                                KC_TRANSPARENT, LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, ST_MACRO_3,     ST_MACRO_4,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_WH_UP,    KC_MS_BTN2,     KC_TRANSPARENT,                                 KC_TRANSPARENT, RSFT(KC_LEFT),  KC_MS_UP,       RSFT(KC_RIGHT), RSFT(KC_DOWN),  KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,   QK_LLCK,                                        KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_MS_BTN3,     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_NO,          KC_KP_9,        KC_KP_8,        KC_KP_7,        KC_NO,                                          KC_NO,          KC_PGDN,        KC_PAGE_UP,     TD(DANCE_4),    KC_NO,          KC_NO,          
    KC_NO,          KC_KP_0,        KC_KP_3,        KC_KP_2,        KC_KP_1,        QK_LLCK,                                        KC_TRANSPARENT, TD(DANCE_5),    TD(DANCE_6),    TD(DANCE_7),    TD(DANCE_8),    KC_NO,          
    KC_TRANSPARENT, QK_LLCK,        KC_KP_6,        KC_KP_5,        KC_KP_4,        KC_DOT,                                         KC_NO,          ST_MACRO_5,     ST_MACRO_6,     KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


const uint16_t PROGMEM combo0[] = { HOME_T, HOME_N, COMBO_END};
const uint16_t PROGMEM combo1[] = { HYPER_F, KC_P, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_Y, HYPER_U, COMBO_END};
const uint16_t PROGMEM combo3[] = { HOME_N, HOME_E, COMBO_END};
const uint16_t PROGMEM combo4[] = { HOME_E, HOME_I, COMBO_END};
const uint16_t PROGMEM combo5[] = { HOME_R, HOME_S, COMBO_END};
const uint16_t PROGMEM combo6[] = { HOME_S, HOME_T, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_UNDS),
    COMBO(combo1, CW_TOGG),
    COMBO(combo2, KC_BSPC),
    COMBO(combo3, MAGIC_2),
    COMBO(combo4, MAGIC_3),
    COMBO(combo5, MAGIC_2),
    COMBO(combo6, MAGIC_3),
};

const custom_shift_key_t custom_shift_keys[] = {
  {TD(DANCE_0), KC_QUOTE}, // Shift TD(DANCE_0) is '
  {KC_SPACE, KC_ENTER}, // Shift ␣ is ↵
  {KC_DOT, KC_EXLM }, // Shift . is !
  //{KC_COLN, KC_SCLN}, // Shift : is ; 
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);//custom shift key codes ends here


bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
  if (keycode == MAGIC) { return false; }
  else if (keycode == REPEAT) { return false; }//tap-hold REPEAT key 19.07.2025
  return true;
}//for implementation of tap-hold Alternate Repeat Key

bool get_repeat_key_eligible_user(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods) {
    switch (keycode) {
        // Ignore Custom Magic Keys
        case MAGIC_2:
        case MAGIC_3:
            return false;
        case KC_A ... KC_Z:
            if ((*remembered_mods & ~(MOD_MASK_SHIFT)) == 0) {
                *remembered_mods &= ~MOD_MASK_SHIFT;
            }
            break;

    }

    return true;
}//added on 30.08.2025

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case HOME_A: return M_TN;
        case HOME_S: return M_SION;
        case HOME_T: return M_THE_1; 
        case KC_W: return M_WHAT;
        case KC_Q: return M_LOCK;
        case KC_Y: return M_YOU; 
        case KC_SPC: return M_THE_2;
        case KC_P1 ... KC_P0:
        case KC_1 ... KC_0: return M_NUM;
        case HOME_O: return M_U;
        case HYPER_U: return M_O;

    }

    return KC_TRNS;
}//for implementaion of tap-hold Alternate Repeat key

bool process_magic_key_2(uint16_t prev_keycode, uint8_t prev_mods){
    switch (prev_keycode){
        case HOME_A:
            SEND_STRING("nd");
            return false;
        case KC_W:
            SEND_STRING("hat");
            return false;
        case HOME_M:
            SEND_STRING("ent");
            return false;
        case HOME_N:
            SEND_STRING("ote:");
            return false;
        case KC_V:
            SEND_STRING("ent wall");
            return false;
        case HOME_T:
            SEND_STRING("hrough");
            return false;
        case HOME_O:
            SEND_STRING("DS");
            return false;
        default:
            return false;
    }
}

bool process_magic_key_3(uint16_t prev_keycode, uint8_t prev_mods){
    switch (prev_keycode){
        case KC_Y:
            SEND_STRING("ou'll");
            return false;
        case HOME_I:
            SEND_STRING("ng");
            return false;
        case HOME_T:
            SEND_STRING("ment");
            return false;
        case KC_P:
            SEND_STRING("aulo Mkali");
            return false;
        case KC_SPC:
            SEND_STRING("and");
            return false;
        case HYPER_U:  
            SEND_STRING("x");
            return false;
        case KC_V:
            SEND_STRING("ent door");
            return false;
        case HOME_O:
            SEND_STRING("DN");
            return false;
        case KC_D:
            SEND_STRING("BR");
            return false;
        default:
            return false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) { return false; }//achordion implentation
  if (!process_sentence_case(keycode, record)) { return false; }//sentence_case implementation
  if (!process_custom_shift_keys(keycode, record)) { return false; }//custom_shift_keys implementation

switch (keycode) {
    case MAGIC_2:
        return process_magic_key_2(get_last_keycode(), get_last_mods());
    case MAGIC_3:
        return process_magic_key_3(get_last_keycode(), get_last_mods());
    case M_TN: 
    if(record->event.pressed){
        SEND_STRING(/*a*/"tion");
    } 
    break; // pressing a then Alt Rep gives "ation"
    case M_SION:
    if(record->event.pressed){
        SEND_STRING(/*s*/"ion");
    }
    break; //pressing s then Alt Rep gives "sion"
    case M_THE_1:
    if(record->event.pressed){
        SEND_STRING(/*t*/"he");
    } 
    break; //pressing t then Alt Rep gives "the"
    case M_WHAT:
    if(record->event.pressed){
        SEND_STRING(/*w*/"hat");
        tap_code16(KC_SPACE);//added 29.06.2025 to press space after "what" is typed
    } 
    break; //pressing w then Alt Rep gives "what"
    case M_THE_2:
    if(record->event.pressed){
        SEND_STRING(/*space*/"the");
    } 
    break; //pressing space then Alt Rep gives "the"
    case M_YOU:
    if(record->event.pressed){
        SEND_STRING(/*y*/"ou");
    }
    break; //pressing y then Alt Rep gives "you"
    case M_NUM:
    if(record->event.pressed){
        tap_code16(KC_UNDS);
    }
    break;
    case M_LOCK:
    if(record->event.pressed){
        SEND_STRING(SS_LCTL(SS_RGUI("q"))); //locks the screen
    }
    break; //pressing a number key followed by a magic key types an underscore
    case MAGIC:  // 2nd layer on hold, Alternate Repeat Key on tap.
      if (record->tap.count) {  // On tap.
        alt_repeat_key_invoke(&record->event);  // Alternate Repeat the last key.
        return false;  // Skip default handling.
      }
    break;
    case REPEAT://4th layer on hold, REPEAT key on tap 19.07.2025
    if (record->tap.count) { //on tap.
        repeat_key_invoke(&record->event);
        return false;
    }
    break;   //for implementation of tap-hold Alternate Repeat Key
    case KC_SPACE:// When the Repeat key follows Space, it behaves as one-shot shift
      if (get_repeat_key_count() > 0) {
        if (record->event.pressed) {
          add_oneshot_mods(MOD_LSFT);
          register_mods(MOD_LSFT);
        } else {
          unregister_mods(MOD_LSFT);
        }
        return false;
      }
      break;
    case M_U:
      if (record->event.pressed){
        SEND_STRING("u");
      }
      break;
      case M_O:
      if (record->event.pressed){
        SEND_STRING("o");
      }
      break;
    //Oryx cases starts after this comment
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRC)SS_DELAY(100)  SS_TAP(X_RBRC)SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_9))SS_DELAY(100)  SS_LSFT(SS_TAP(X_0))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_LBRC))SS_DELAY(100)  SS_LSFT(SS_TAP(X_RBRC))SS_DELAY(100)  SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_RGUI(SS_TAP(X_V)));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_RGUI(SS_TAP(X_C)));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_PGDN)));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_RCTL(SS_TAP(X_PAGE_UP)));
    }
    break;

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_74_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(74,255,255);
      }
      return false;
    case HSV_169_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(169,255,255);
      }
      return false;
  }
  return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[9];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
    }
    if(state->count > 3) {
        tap_code16(KC_COMMA);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_COMMA); break;
        case DOUBLE_TAP: register_code16(KC_EXLM); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COMMA); register_code16(KC_COMMA);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_COMMA); break;
        case DOUBLE_TAP: unregister_code16(KC_EXLM); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COMMA); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LBRC);
        tap_code16(KC_LBRC);
        tap_code16(KC_LBRC);
    }
    if(state->count > 3) {
        tap_code16(KC_LBRC);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_LBRC); break;
        case DOUBLE_TAP: register_code16(KC_RBRC); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LBRC); register_code16(KC_LBRC);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_LBRC); break;
        case DOUBLE_TAP: unregister_code16(KC_RBRC); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LBRC); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LPRN);
        tap_code16(KC_LPRN);
        tap_code16(KC_LPRN);
    }
    if(state->count > 3) {
        tap_code16(KC_LPRN);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_LPRN); break;
        case DOUBLE_TAP: register_code16(KC_RPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LPRN); register_code16(KC_LPRN);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_LPRN); break;
        case DOUBLE_TAP: unregister_code16(KC_RPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LPRN); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LCBR);
        tap_code16(KC_LCBR);
        tap_code16(KC_LCBR);
    }
    if(state->count > 3) {
        tap_code16(KC_LCBR);
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_LCBR); break;
        case DOUBLE_TAP: register_code16(KC_RCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LCBR); register_code16(KC_LCBR);
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_LCBR); break;
        case DOUBLE_TAP: unregister_code16(KC_RCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LCBR); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_HOME);
        tap_code16(KC_HOME);
        tap_code16(KC_HOME);
    }
    if(state->count > 3) {
        tap_code16(KC_HOME);
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_HOME); break;
        case DOUBLE_TAP: register_code16(KC_END); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_HOME); register_code16(KC_HOME);
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_HOME); break;
        case DOUBLE_TAP: unregister_code16(KC_END); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_HOME); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
    }
    if(state->count > 3) {
        tap_code16(KC_MINUS);
    }
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_MINUS); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_SHIFT); break;
        case DOUBLE_TAP: register_code16(KC_SLASH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MINUS); register_code16(KC_MINUS);
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(KC_MINUS); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_SHIFT); break;
        case DOUBLE_TAP: unregister_code16(KC_SLASH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MINUS); break;
    }
    dance_state[5].step = 0;
}
void on_dance_6(tap_dance_state_t *state, void *user_data);
void dance_6_finished(tap_dance_state_t *state, void *user_data);
void dance_6_reset(tap_dance_state_t *state, void *user_data);

void on_dance_6(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PLUS);
        tap_code16(KC_PLUS);
        tap_code16(KC_PLUS);
    }
    if(state->count > 3) {
        tap_code16(KC_PLUS);
    }
}

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_PLUS); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_GUI); break;
        case DOUBLE_TAP: register_code16(KC_ASTR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PLUS); register_code16(KC_PLUS);
    }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_PLUS); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_GUI); break;
        case DOUBLE_TAP: unregister_code16(KC_ASTR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PLUS); break;
    }
    dance_state[6].step = 0;
}
void on_dance_7(tap_dance_state_t *state, void *user_data);
void dance_7_finished(tap_dance_state_t *state, void *user_data);
void dance_7_reset(tap_dance_state_t *state, void *user_data);

void on_dance_7(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_ALT); break;
        case DOUBLE_TAP: register_code16(KC_ENTER); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_ALT); break;
        case DOUBLE_TAP: unregister_code16(KC_ENTER); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[7].step = 0;
}
void on_dance_8(tap_dance_state_t *state, void *user_data);
void dance_8_finished(tap_dance_state_t *state, void *user_data);
void dance_8_reset(tap_dance_state_t *state, void *user_data);

void on_dance_8(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
    }
    if(state->count > 3) {
        tap_code16(KC_QUOTE);
    }
}

void dance_8_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_QUOTE); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: register_code16(KC_DQUO); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_QUOTE); register_code16(KC_QUOTE);
    }
}

void dance_8_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_QUOTE); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_DQUO); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_QUOTE); break;
    }
    dance_state[8].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
};
