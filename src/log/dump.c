#include "main.h"

#include "internal.h"


#ifdef ENABLE_DEBUG


#define HEX_BUF_SIZE 128
#define HEX_CHARS "0123456789abcdef"

void log_dump_data(const unsigned char *data, size_t size)
{
    char hex_buf[HEX_BUF_SIZE];

    extern log_output_t *log_outputs;
    extern int log_outputs_count;

    log_output_t *out = log_outputs;

    for (int oi = 0; oi < log_outputs_count; oi++, out++) {
        // Skip

        if (out->stream_error || LOG_DUMP < out->level_from || LOG_DUMP > out->level_to)
            continue;

        // Hex dump

        size_t di = 0;

        while (di < size) {
            size_t offset = di;
            int bi = 0;

            while (di < size) {
                hex_buf[bi++] = HEX_CHARS[data[di] >> 4];
                hex_buf[bi++] = HEX_CHARS[data[di] & 0xF];

                di++;

                if (!(di % 32))
                    break;

                hex_buf[bi++] = ' ';

                if (!(di % 4))
                    hex_buf[bi++] = ' ';

                if (!(di % 8))
                    hex_buf[bi++] = ' ';
            }

            hex_buf[bi++] = '\0';

            // Output

            if (out->type == LOG_TYPE_SYSLOG) {
                syslog_dump(offset, hex_buf);
                continue;
            }

            fprintf(out->stream, "%8zu    %s\n", offset, hex_buf);
        }
    }
}

#endif
