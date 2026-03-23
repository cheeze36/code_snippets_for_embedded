#include "ring_buffer.h"



void message_rb_init(message_buffer_t* buffer)
{
    buffer->head = 0;
    buffer->tail = 0;
    buffer->count = 0;
    buffer->current_display_index = 0;
}

bool message_rb_full(const message_buffer_t* buffer)
{
    return buffer->count == MAX_MESSAGES;
}

bool message_rb_empty(const message_buffer_t* buffer)
{
    return buffer->count == 0;
}

uint8_t message_rb_size(const message_buffer_t* buffer)
{
    return buffer->count;
}

bool message_rb_push(message_buffer_t* buffer, const letter_t* msg)
{
    if (buffer->count == MAX_MESSAGES)
    {
        // buffer full → overwrite oldest
        buffer->tail = (buffer->tail + 1) % MAX_MESSAGES;
        // count stays MAX_MESSAGES
    }
    else
    {
        buffer->count++;
    }

    buffer->messages[buffer->head] = *msg;
    buffer->head = (buffer->head + 1) % MAX_MESSAGES;

    return true;
}


bool message_rb_pop(message_buffer_t* buffer, letter_t* out)
{
    if (message_rb_empty(buffer))
    {
        return false;
    }

    *out = buffer->messages[buffer->tail];
    buffer->tail = (buffer->tail + 1) % MAX_MESSAGES;
    buffer->count--;
    return true;
}

bool message_rb_peek(const message_buffer_t* buffer, letter_t* out)
{
    if (message_rb_empty(buffer))
    {
        return false;
    }
    *out = buffer->messages[buffer->tail];
    return true;
}


void alert_rb_init(alert_buffer_t* buffer)
{
    buffer->head = 0;
    buffer->tail = 0;
    buffer->count = 0;
    buffer->current_display_index = 0;
}

bool alert_rb_full(const alert_buffer_t* buffer)
{
    return buffer->count == MAX_ALERTS;
}

bool alert_rb_empty(const alert_buffer_t* buffer)
{
    return buffer->count == 0;
}

uint8_t alert_rb_size(const alert_buffer_t* buffer)
{
    return buffer->count;
}

bool alert_rb_push(alert_buffer_t* buffer, const alert_t* alert)
{
    if (buffer->count == MAX_ALERTS)
    {
        // buffer full → overwrite oldest
        buffer->tail = (buffer->tail + 1) % MAX_ALERTS;
        // count stays MAX_ALERTS
    }
    else
    {
        buffer->count++;
    }

    buffer->alerts[buffer->head] = *alert;
    buffer->head = (buffer->head + 1) % MAX_ALERTS;

    return true;
}


bool alert_rb_pop(alert_buffer_t* buffer, alert_t* out)
{
    if (alert_rb_empty(buffer))
    {
        return false;
    }

    *out = buffer->alerts[buffer->tail];
    buffer->tail = (buffer->tail + 1) % MAX_ALERTS;
    buffer->count--;
    return true;
}

bool alert_rb_peek(const alert_buffer_t* buffer, alert_t* out)
{
    if (alert_rb_empty(buffer))
    {
        return false;
    }
    *out = buffer->alerts[buffer->tail];
    return true;
}
