#ifndef HELLO_WORLD_RING_BUFFER_H
#define HELLO_WORLD_RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>
#include "models/alert.h"
#include "models/letter.h"

#define MAX_MESSAGES 20
#define MAX_ALERTS 20


/**
 * @brief a ring buffer to hold messages
 */
typedef struct
{
    letter_t messages[MAX_MESSAGES];
    uint8_t head;
    uint8_t tail;
    uint8_t count;
    uint8_t current_display_index;
} message_buffer_t;

/**
 * @brief a ring buffer to hold alerts
 */
typedef struct
{
    alert_t alerts[MAX_ALERTS];
    uint8_t head;
    uint8_t tail;
    uint8_t count;
    uint8_t current_display_index;
} alert_buffer_t;

void message_rb_init(message_buffer_t* buffer);
bool message_rb_push(message_buffer_t* buffer, const letter_t* msg);
bool message_rb_pop(message_buffer_t* buffer, letter_t* out);
bool message_rb_peek(const message_buffer_t* buffer, letter_t* out);
bool message_rb_empty(const message_buffer_t* buffer);
bool message_rb_full(const message_buffer_t* buffer);
uint8_t message_rb_size(const message_buffer_t* buffer);

void alert_rb_init(alert_buffer_t* buffer);
bool alert_rb_push(alert_buffer_t* buffer, const alert_t* alert);
bool alert_rb_pop(alert_buffer_t* buffer, alert_t* out);
bool alert_rb_peek(const alert_buffer_t* buffer, alert_t* out);
bool alert_rb_empty(const alert_buffer_t* buffer);
bool alert_rb_full(const alert_buffer_t* buffer);
uint8_t alert_rb_size(const alert_buffer_t* buffer);


#endif //HELLO_WORLD_RING_BUFFER_H
