

#define DFI_TX_HEADER { 0x44, 0x66, 0x54, 0x78}

enum DfiCustomTxType {
    None   = 0,
    Reject = 1,  // Invalid TX type. Returned by GuessCustomTxType on invalid custom TX.

    // masternodes:
    CreateMasternode = 'C',
    ResignMasternode = 'R',
    UpdateMasternode = 'm',
    // custom tokens:
    CreateToken    = 'T',
    MintToken      = 'M',
    BurnToken      = 'F',
    UpdateToken    = 'N',  // previous type, only DAT flag triggers
    UpdateTokenAny = 'n',  // new type of token's update with any flags/fields possible
    // poolpair
    CreatePoolPair      = 'p',
    UpdatePoolPair      = 'u',
    PoolSwap            = 's',
    PoolSwapV2          = 'i',
    AddPoolLiquidity    = 'l',
    RemovePoolLiquidity = 'r',
    // accounts
    UtxosToAccount        = 'U',
    AccountToUtxos        = 'b',
    AccountToAccount      = 'B',
    AnyAccountsToAccounts = 'a',
    SmartContract         = 'K',
    FutureSwap            = 'Q',
    // set governance variable
    SetGovVariable       = 'G',
    SetGovVariableHeight = 'j',
    // Auto auth TX
    AutoAuthPrep = 'A',
    // oracles
    AppointOracle       = 'o',
    RemoveOracleAppoint = 'h',
    UpdateOracleAppoint = 't',
    SetOracleData       = 'y',
    // ICX
    ICXCreateOrder   = '1',
    ICXMakeOffer     = '2',
    ICXSubmitDFCHTLC = '3',
    ICXSubmitEXTHTLC = '4',
    ICXClaimDFCHTLC  = '5',
    ICXCloseOrder    = '6',
    ICXCloseOffer    = '7',
    // Loans
    SetLoanCollateralToken = 'c',
    SetLoanToken           = 'g',
    UpdateLoanToken        = 'x',
    LoanScheme             = 'L',
    DefaultLoanScheme      = 'd',
    DestroyLoanScheme      = 'D',
    Vault                  = 'V',
    CloseVault             = 'e',
    UpdateVault            = 'v',
    DepositToVault         = 'S',
    WithdrawFromVault      = 'J',
    PaybackWithCollateral  = 'W',
    TakeLoan               = 'X',
    PaybackLoan            = 'H',
    PaybackLoanV2          = 'k',
    AuctionBid             = 'I',
    // Marker TXs
    FutureSwapExecution = 'q',
    FutureSwapRefund    = 'w',
    TokenSplit          = 'P',
    // On-Chain-Gov
    CreateCfp                 = 'z',
    Vote                      = 'O',  // NOTE: Check whether this overlapping with CreateOrder above is fine
    CreateVoc                 = 'E',  // NOTE: Check whether this overlapping with DestroyOrder above is fine
    ProposalFeeRedistribution = 'Y',
    UnsetGovVariable          = 'Z',
};




int get_dfi_tx_type(const uint8_t script[],
                       size_t script_len,
                       char *out,
                       size_t out_len,
                       uint64_t* amount,
                       global_context_t *G_coin_config);