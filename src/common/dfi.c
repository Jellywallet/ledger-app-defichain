
#include <stddef.h>
#include <stdint.h>
#include <limits.h>
#include <inttypes.h>

#include "../common/bip32.h"
#include "../common/buffer.h"
#include "../common/read.h"
#include "../common/script.h"
#include "../common/segwit_addr.h"

#ifndef SKIP_FOR_CMOCKA
#include "../crypto.h"
#endif

#include "dfi.h"

int getScript(const uint8_t script[], size_t script_len, uint8_t *out);

#ifndef IS_DEFICHAIN_TESTNET
size_t tokenToText(uint64_t token, char *out, size_t out_len) {
    switch (token) {
        case 0:
            snprintf(out, out_len, "DFI");
            return 3;
        case 1:
            snprintf(out, out_len, "ETH");
            return 3;
        case 2:
            snprintf(out, out_len, "BTC");
            return 3;
        case 3:
            snprintf(out, out_len, "USDT");
            return 4;
        case 7:
            snprintf(out, out_len, "DOGE");
            return 4;
        case 9:
            snprintf(out, out_len, "LTC");
            return 3;
        case 11:
            snprintf(out, out_len, "BCH");
            return 3;
        case 13:
            snprintf(out, out_len, "USDC");
            return 4;
        case 15:
            snprintf(out, out_len, "DUSD");
            return 4;
        case 16:
            snprintf(out, out_len, "TSLA/v1");
            return 7;
        case 19:
            snprintf(out, out_len, "BABA");
            return 4;
        case 20:
            snprintf(out, out_len, "GME/v1");
            return 6;
        case 21:
            snprintf(out, out_len, "PLTR");
            return 4;
        case 22:
            snprintf(out, out_len, "AAPL");
            return 4;
        case 23:
            snprintf(out, out_len, "GOOGL/v1");
            return 8;
        case 24:
            snprintf(out, out_len, "ARKK");
            return 4;
        case 26:
            snprintf(out, out_len, "SPY");
            return 3;
        case 27:
            snprintf(out, out_len, "QQQ");
            return 3;
        case 28:
            snprintf(out, out_len, "GLD");
            return 3;
        case 29:
            snprintf(out, out_len, "SLV");
            return 3;
        case 30:
            snprintf(out, out_len, "PDBC");
            return 4;
        case 31:
            snprintf(out, out_len, "VNQ");
            return 3;
        case 34:
            snprintf(out, out_len, "URTH");
            return 4;
        case 37:
            snprintf(out, out_len, "TLC");
            return 3;
        case 47:
            snprintf(out, out_len, "BURN");
            return 4;
        case 49:
            snprintf(out, out_len, "AMZN/v1");
            return 7;
        case 50:
            snprintf(out, out_len, "COIN");
            return 4;
        case 51:
            snprintf(out, out_len, "EEM");
            return 3;
        case 52:
            snprintf(out, out_len, "NVDA");
            return 4;
        case 57:
            snprintf(out, out_len, "MSFT");
            return 4;
        case 58:
            snprintf(out, out_len, "VOO");
            return 3;
        case 59:
            snprintf(out, out_len, "FB");
            return 2;
        case 60:
            snprintf(out, out_len, "NFLX");
            return 4;
        case 65:
            snprintf(out, out_len, "DIS");
            return 3;
        case 66:
            snprintf(out, out_len, "MSTR");
            return 4;
        case 67:
            snprintf(out, out_len, "MCHI");
            return 4;
        case 68:
            snprintf(out, out_len, "INTC");
            return 4;
        case 73:
            snprintf(out, out_len, "PYPL");
            return 4;
        case 74:
            snprintf(out, out_len, "KO");
            return 2;
        case 75:
            snprintf(out, out_len, "BRK.B");
            return 4;
        case 76:
            snprintf(out, out_len, "PG");
            return 2;
        case 81:
            snprintf(out, out_len, "SAP");
            return 3;
        case 82:
            snprintf(out, out_len, "CS");
            return 2;
        case 83:
            snprintf(out, out_len, "GSG");
            return 4;
        case 84:
            snprintf(out, out_len, "URA");
            return 3;
        case 89:
            snprintf(out, out_len, "AMZN");
            return 4;
        case 91:
            snprintf(out, out_len, "PPLT");
            return 4;
        case 92:
            snprintf(out, out_len, "GOVT");
            return 4;
        case 93:
            snprintf(out, out_len, "XOM");
            return 3;
        case 94:
            snprintf(out, out_len, "TAN");
            return 3;
        case 99:
            snprintf(out, out_len, "GOOGL");
            return 4;
        case 103:
            snprintf(out, out_len, "GME");
            return 3;
        case 105:
            snprintf(out, out_len, "JNJ");
            return 3;
        case 106:
            snprintf(out, out_len, "DAX");
            return 3;
        case 107:
            snprintf(out, out_len, "GS");
            return 2;
        case 108:
            snprintf(out, out_len, "ADDYY");
            return 5;
        case 113:
            snprintf(out, out_len, "TSLA");
            return 4;
        case 115:
            snprintf(out, out_len, "UL");
            return 4;
        case 116:
            snprintf(out, out_len, "UNG");
            return 3;
        case 117:
            snprintf(out, out_len, "USO");
            return 4;
        case 118:
            snprintf(out, out_len, "WMT");
            return 3;
        case 124:
            snprintf(out, out_len, "csETH");
            return 5;
        case 126:
            snprintf(out, out_len, "ARKX");
            return 4;
        case 127:
            snprintf(out, out_len, "XLE");
            return 3;
        case 128:
            snprintf(out, out_len, "Arb");
            return 3;
        case 129:
            snprintf(out, out_len, "Ira");
            return 3;
        case 130:
            snprintf(out, out_len, "EFC");
            return 3;
        case 131:
            snprintf(out, out_len, "SPZY");
            return 4;
        case 132:
            snprintf(out, out_len, "DFG");
            return 5;
        case 133:
            snprintf(out, out_len, "DGT");
            return 3;
        case 134:
            snprintf(out, out_len, "JULE");
            return 4;
        case 135:
            snprintf(out, out_len, "MCA");
            return 3;
        case 136:
            snprintf(out, out_len, "ALC");
            return 3;
        case 137:
            snprintf(out, out_len, "STEF");
            return 4;
        case 138:
            snprintf(out, out_len, "DF1");
            return 3;
        case 139:
            snprintf(out, out_len, "BIO");
            return 3;
        case 140:
            snprintf(out, out_len, "TCMN");
            return 4;
        case 141:
            snprintf(out, out_len, "BUSH2");
            return 5;
        case 142:
            snprintf(out, out_len, "wBTC");
            return 4;
        case 144:
            snprintf(out, out_len, "wETH");
            return 4;
        case 145:
            snprintf(out, out_len, "ICC");
            return 3;
        case 146:
            snprintf(out, out_len, "DFIS");
            return 4;
        case 147:
            snprintf(out, out_len, "HOPI");
            return 4;
        case 148:
            snprintf(out, out_len, "Monaco");
            return 6;
        case 149:
            snprintf(out, out_len, "LEG");
            return 3;
        default:
            snprintf(out, out_len, "%d", (int) token);
    }
}
#else

size_t tokenToText(uint64_t token, char *out, size_t out_len) {
    switch (token) {
        case 0:
            snprintf(out, out_len, "DFI");
            return 3;
        case 1:
            snprintf(out, out_len, "BTC");
            return 3;
        case 2:
            snprintf(out, out_len, "ETH");
            return 3;
        case 5:
            snprintf(out, out_len, "USDT");
            return 4;
        case 6:
            snprintf(out, out_len, "DFI");
            return 3;
        case 10:
            snprintf(out, out_len, "TWTR");
            return 4;
        case 11:
            snprintf(out, out_len, "DUSD");
            return 3;
        case 12:
            snprintf(out, out_len, "MSFT");
            return 4;
        case 13:
            snprintf(out, out_len, "GOOGL");
            return 5;
        case 14:
            snprintf(out, out_len, "FB");
            return 2;
        case 19:
            snprintf(out, out_len, "TSLA");
            return 4;
        case 22:
            snprintf(out, out_len, "USDC");
            return 4;
        case 25:
            snprintf(out, out_len, "EUROC");
            return 5;
        default:
            return snprintf(out, out_len, "%d", (int) token);
    }
}
#endif

int get_dfi_tx_type(const uint8_t script[],
                    size_t script_len,
                    char *out,
                    size_t out_len,
                    uint64_t *amount,
                    global_context_t *G_coin_config) {
    if (script_len <= 0) {
        return -1;
    }

    PRINTF("DFI_SCRIPT (%d): ", script_len);
    for (size_t i = 0; i < script_len; i++) {
        PRINTF("%02X", script[i]);
    }
    PRINTF("\n");

    char txType = script[0];

    PRINTF("TxType is %c\n", txType);
    switch (txType) {
        case PoolSwap: {
            PRINTF("PARSING PoolSwap\n");
            int offset = 1;
            uint8_t from_address[MAX_ADDRESS_LENGTH_STR];
            int from_address_len = getScript(&script[offset], script_len - offset, from_address);
            offset += from_address_len;

            uint64_t from_token = -1;
            offset += varint_read(&script[offset], script_len - offset, &from_token);

            char from_token_str[10];
            size_t from_token_str_len = tokenToText(from_token, from_token_str, 10);

            uint64_t from_amount = read_u64_le(&script[offset], 0);
            offset += 8;

            *amount = from_amount;

            uint8_t to_address[MAX_ADDRESS_LENGTH_STR];
            int to_address_len = getScript(&script[offset], script_len - offset, to_address);
            offset += to_address_len;

            uint64_t to_token = -1;
            offset += varint_read(script + offset, script_len - offset, &to_token);

            char to_token_str[10];
            size_t to_token_str_len = tokenToText(to_token, to_token_str, 10);

            uint64_t max_price = read_u64_be(script, offset);
            offset += 8;

            uint64_t max_price_fraction = read_u64_be(script, offset);
            offset += 8;

            int out_ctr = 5;
            strcpy(out, "Swap ");

            strcpy(out + out_ctr, from_token_str);
            out_ctr += from_token_str_len;

            strcpy(out + out_ctr, " to d");
            out_ctr += 5;

            strcpy(out + out_ctr, to_token_str);
            out_ctr += to_token_str_len;
            return out_ctr;
        }
        case UtxosToAccount: {
            strcpy(out, "Utxo to Account");
            return 15;
        }
        case AccountToUtxos: {
            strcpy(out, "Account to Utxo");
            return 15;
        }
        case AccountToAccount: {
            int offset = 1;
            uint8_t from_address[MAX_ADDRESS_LENGTH_STR];
            int from_address_len = getScript(&script[offset], script_len - offset, from_address);
            offset += from_address_len;

            PRINTF("FromAddressLen: %d (offset %d)\n", from_address_len, offset);

            int accountLen = script[offset];
            offset++;

            PRINTF("Account len is %d\n", accountLen);

            uint8_t to_address[MAX_ADDRESS_LENGTH_STR];
            int to_address_len = getScript(&script[offset], script_len - offset, to_address);
            offset += to_address_len;

            char output_address[MAX(MAX_ADDRESS_LENGTH_STR + 1, MAX_OPRETURN_OUTPUT_DESC_SIZE)];
            int address_len = get_script_address(to_address,
                                                 to_address_len - 1,
                                                 G_coin_config,
                                                 output_address,
                                                 sizeof(output_address));

            int tokenLen = script[offset];
            offset++;

            uint32_t token = read_u32_le(&script[offset], 0);
            offset += 4;

            char token_str[10];
            size_t token_str_len = tokenToText(token, token_str, 10);

            uint64_t amountU64 = read_u64_le(&script[offset], 0);
            offset += 8;
            *amount = amountU64;

            int out_ctr = 6;
            strcpy(out, "Send d");

            strcpy(out + out_ctr, token_str);
            out_ctr += token_str_len;

            strcpy(out + out_ctr, " to ");
            out_ctr += 4;

            strcpy(out + out_ctr, output_address);
            out_ctr += address_len;
            return out_ctr;
        }
        case AnyAccountsToAccounts: {
            int offset = 1;

            int from_account_len = script[offset];
            offset++;

            uint8_t from_address[MAX_ADDRESS_LENGTH_STR];
            int from_address_len = getScript(&script[offset], script_len - offset, from_address);
            offset += from_address_len;

            int fromTokenLen = script[offset];
            offset++;

            uint64_t from_token = -1;
            offset += varint_read(&script[offset], script_len - offset, &from_token);

            char from_token_str[10];
            size_t from_token_str_len = tokenToText(from_token, from_token_str, 10);

            uint64_t from_amount = read_u64_le(&script[offset], 0);
            offset += 8;

            int to_account_len = script[offset];
            offset++;

            uint8_t to_address[MAX_ADDRESS_LENGTH_STR];
            int to_address_len = getScript(&script[offset], script_len - offset, to_address);
            offset += to_address_len;

            int tokenLen = script[offset];
            offset++;

            uint64_t token = -1;
            offset += varint_read(&script[offset], script_len - offset, &token);

            char token_str[10];
            size_t token_str_len = tokenToText(token, token_str, 10);

            uint64_t to_amount = read_u64_le(&script[offset], 0);
            offset += 8;

            *amount = to_amount;
            return 0;
        }
        case AutoAuthPrep: {
            int out_ctr = 17;
            strcpy(out, "Authorize account");
            return out_ctr;
        }
        case AddPoolLiquidity: {
            int offset = 1;
            int pairs = script[offset];
            offset++;

            uint8_t to_address[MAX_ADDRESS_LENGTH_STR];
            int to_address_len = getScript(&script[offset], script_len - offset, to_address);
            offset += to_address_len;

            int balances = script[offset];
            offset++;

            uint32_t token = read_u32_le(&script[offset], 0);
            offset += 4;

            char token_str[10];
            size_t token_str_len = tokenToText(token, token_str, 10);

            uint64_t amountU64 = read_u64_le(&script[offset], 0);
            offset += 8;

            uint32_t token2 = read_u32_le(&script[offset], 0);
            offset += 4;

            char token_str2[10];
            size_t token_str_len2 = tokenToText(token2, token_str2, 10);

            uint64_t amountU642 = read_u64_le(&script[offset], 0);
            offset += 8;
            *amount = amountU642;

            uint8_t share_address[MAX_ADDRESS_LENGTH_STR];
            int shared_address_len = getScript(&script[offset], script_len - offset, share_address);
            offset += shared_address_len;

            char output_address[MAX(MAX_ADDRESS_LENGTH_STR + 1, MAX_OPRETURN_OUTPUT_DESC_SIZE)];
            int address_len = get_script_address(share_address,
                                                 shared_address_len - 1,
                                                 G_coin_config,
                                                 output_address,
                                                 sizeof(output_address));

            int out_ctr = 17;
            strcpy(out, "Add Liquidity to ");

            if (token > 0) {
                strcpy(out + out_ctr, "d");
                out_ctr++;
            }

            strcpy(out + out_ctr, token_str);
            out_ctr += token_str_len;

            strcpy(out + out_ctr, "-d");
            out_ctr += 2;

            strcpy(out + out_ctr, token_str2);
            out_ctr += token_str_len2;

            strcpy(out + out_ctr, " share address: ");
            out_ctr += 16;
            strcpy(out + out_ctr, output_address);
            out_ctr += address_len;
            return out_ctr;
        }
        case RemovePoolLiquidity: {
            int offset = 1;

            uint8_t to_address[MAX_ADDRESS_LENGTH_STR];
            int to_address_len = getScript(&script[offset], script_len - offset, to_address);
            offset += to_address_len;

            uint32_t token = read_u32_le(&script[offset], 0);
            offset += 4;

            char token_str[10];
            size_t token_str_len = tokenToText(token, token_str, 10);

            uint64_t amountU64 = read_u64_le(&script[offset], 0);
            offset += 8;

            int out_ctr = 16;
            strcpy(out, "Remove Liquidity");
            return out_ctr;
        }
        default:
            return -1;
    }

    return 0;
}

int getScript(const uint8_t script[], size_t script_len, uint8_t *out) {
    size_t len = script[0];
    memcpy(out, &script[1], len);
    return len + 1;
}

