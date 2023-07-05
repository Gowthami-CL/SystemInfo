//static void netSrvMgr_start();
static void systemInfo_Loop();

static IARM_Result_t isAvailable(void *arg);

IARM_Bus_RegisterCall(IARM_BUS_SYSTEMINFO_API_isAvailable, isAvailable);

#ifdef ENABLE_SD_NOTIFY
    sd_notifyf(0, "READY=1\n"
               "STATUS=systemInfo is Successfully Initialized\n"
               "MAINPID=%lu",
               (unsigned long) getpid());
#endif
    //netSrvMgr_start();
    systemInfo_Loop();

IARM_Result_t isAvailable(void *arg)
{
    LOG_ENTRY_EXIT;
    LOG_INFO("[%s] IARM_BUS_SYSTEMINFO_API_isAvailable is called", MODULE_NAME);
    return IARM_RESULT_SUCCESS;
}
